import sys
import math
from PortersStemmer import porters
import pickle

# Computes tf-idf weight of 'term' w.r.t 'docuId'
def tfIdfWeight(corpus, term, docuId, idf):
	"""
	tf_t,d = 1 + log(freq_t,d)
	idf_t from parameter
	return tf-idf = (tf_t,d * idf_t)
	"""
	if docuId == -1:	# for a query
		tfWeight = float(1.0 + math.log10(corpus[term]))
	else:
		tfWeight = float(1.0 + math.log10(corpus[term][docuId]))
	return (tfWeight * idf[term])

# Computes frequency of each term in query
# Input: query
# Output: A dictionary which maps each term in query to its frequency in the query
def queryTermFreq(query):
	"""
	Compute freq of each term in query
	"""
	query = porters(query)
	words_in_query = query.split()
	queryDict = {}
	for word in words_in_query:
		if word in queryDict:
			queryDict[word] += 1
		else:
			queryDict[word] = 1
	
	return queryDict

# Computes inverse document frequency of every term in the corpus
# Input: Corpus dictionaary, Number of documents
# Output: A dictionary which maps each term in the vocabulary to its idf
def inverseDocFreq(corpus, noDocs):
	"""
	idf_t = log(N/freq_t)
	"""
	print "Computing inverse document frequencies..."
	idf = {}
	for term in corpus:
		dft = len(corpus[term])
		idf[term] = math.log10((float(noDocs)) / dft)
	return idf

# Computes magnitude of document vector (a vector which has a component equal to weight (tf-idf) for each term)
# Input: Corpus dictionary, Inverse document frequency dictionary
# Output: A dictionary which maps each document ID to its weight vector magnitude
def docuLengths(corpus, idf):
	"""
	length(docId) = sqrt(w1^2 + w2^2 + w3^2 + ... Wt^2)
		where 'wi' is 'tf-idf' weight of ith term of that document
	"""
	ans = {}
	for term in corpus:
		postingList = corpus[term]
		for docId in postingList:
			if docId in ans:
				ans[docId] += tfIdfWeight(corpus, term, docId, idf) ** 2
			else:
				ans[docId] = tfIdfWeight(corpus, term, docId, idf) ** 2
	for docId in ans:
		ans[docId] = math.sqrt(ans[docId])
	return ans

# Computes cosine score of each document in the corpus, and sorts them in the decreasing order of scores.
# Input: Query term frequency dictionary, Corpus dictionary, inverse doc freq dictionary
# Output: A list of lists each with two components, docId and score (ex: [[3, 0.9], [1, 0.8], [0, 0.6], [2, 0.5]])
def CosineScores(queryTF, corpus, idf):
	"""
	wrt query 'q', Cosine_score(docId) = (wd1*wq1 + wd2*wq2 + ... + wdt*wqt) / (length(docId) * length(q))
						where 'wdi' is 'tf-idf' weight of ith term wrt document
						  and 'wqi' is 'tf-idf' weight of ith term wrt query
	length(q) is redundant in denominator because it is same for each query and doesn't matter for scoring, so we skip it.
	"""
	print "Computing the cosine scores of each document..."
	scoreDict = {}
	for queryTerm in queryTF:
		if queryTerm not in corpus:
			continue
		postList = corpus[queryTerm]
		for docId in postList:
			if docId in scoreDict:
				scoreDict[docId] += float(tfIdfWeight(corpus, queryTerm, docId, idf) * tfIdfWeight(queryTF, queryTerm, -1, idf))
			else:
				scoreDict[docId] = float(tfIdfWeight(corpus, queryTerm, docId, idf) * tfIdfWeight(queryTF, queryTerm, -1, idf))

	if len(scoreDict) == 0:
		print "No relevant documents found\n"
		return None
		
	# Normalizing:			
	documentLengths = docuLengths(corpus, idf)
	for docId in scoreDict:
		scoreDict[docId] /= float(documentLengths[docId])
		
	scoreList = []
	for docId in scoreDict:
		temp = []
		temp.append(docId)
		temp.append(scoreDict[docId])
		scoreList.append(temp)
	
	scoreList.sort(key=lambda x:-1*x[1])
	return scoreList

# The driver function for the program
if __name__ == '__main__':
	if len(sys.argv) > 1:
		noDocs = sys.argv[1]	#19987		# Total number of documents in the corpus
	else:
		print "Usage: \n$ python VectorSpaceModel.py [NumDocs]"
		sys.exit(0)
	
	print "Reading postings list from the pickle..."
	with open('corpus.pickle', 'rb') as f:
		postingsList = pickle.load(f)
	
	idf = inverseDocFreq(postingsList, noDocs)
	
	while True:
		print "\nEnter the query:",
		query = str(raw_input())
		query = porters(query)
	
		querytf = queryTermFreq(query)
		
		scoresFinal = CosineScores(querytf, postingsList, idf)
		
		if scoresFinal == None:
			continue
		
		print
		for i in range(min(10, len(scoresFinal))):
			if scoresFinal[i][1] > 0:
				print str(i + 1) + ". Document #" + str(scoresFinal[i][0]) + " has " + str(scoresFinal[i][1]) + " score."
		print
