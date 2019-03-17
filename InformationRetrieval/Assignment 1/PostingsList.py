import os
import sys
import nltk
from os.path import join, getsize
from PortersStemmer import porters
import pickle

# Tokenize the corpus using nltk tokenizer
# Input: Reads a directory name which may contain several directories and files to be searched
# Output: A dictionary which maps each docId to a list of tokens in that document
def tokenization(dirName):
	"""
	Recursively crawl through each file (if file is a directory, then crawl through each file in it recursively),
	and open the files. Then read each line and call word_tokenize() method of nltk module to get the tokens of the line.
	Store tokens of each file in a list and map it to the file name in the dictionary.
	"""
	print "Tokenizing..."
	tokensDict = {}
	for root, dirs, files in os.walk(dirName):
		for file in files:
			try:
				tokensList = []
				fileDescriptor = open(join(root, file))
				for line in fileDescriptor:
					tokens = nltk.word_tokenize(line)
					for token in tokens:
						tokensList.append(token)
				tokensDict[file] = tokensList
				fileDescriptor.close()
			except:
				print "Exception", file
				pass
	return tokensDict

# Normalizes by stemming the tokens of the corpus
# Input: Calls tokenization() to get the dictionary of tokens
# Output: A dictionary which maps each docId to a list of stemmed terms in that document
def stemming(dirName):
	"""
	Call porters() method on each token which uses Porters algorithm to stem the tokens.
	Store them in a list corresponding to each file and map them to the file name.
	"""
	stemmDict = {}
	tokensDict = tokenization(dirName)
	print "Stemming..."
	for docId in tokensDict:
		stemmList = []
		for token in tokensDict[docId]:
			stemmList.append(porters(token)[:-1])
		stemmDict[docId] = stemmList
	return stemmDict

# Creates postings list of the corpus
# Input: Calls stemming() to retrieve the dictionary of stemmed terms
# Output: A dictionary of postings lists which maps each term in the vocabulary to a dictionary 
#	which in turn maps each docuId to th efrequency of that term appearing in that document
#	ex: {'affect': {0: 155, 1: 20, 2: 6},
#		 'gossip': {1: 18, 2: 11},
#		 'wuther': {0: 26, 2: 13}}
def postingsList(dirName):
	"""
	Create postings list for each term from stemmed terms by assigning frequency of it in each document.
	"""
	postingsLists = {}
	stemList = stemming(dirName)
	print "Creating postings list..."
	
	for docId in stemList:
		for term in stemList[docId]:
			if term not in postingsLists:
				tempDict = {}
				tempDict[int(docId)] = 1
				postingsLists[term] = tempDict
			else:
				tempDict2 = postingsLists[term]
				if int(docId) not in tempDict2:
					tempDict2[int(docId)] = 1
				else:
					tempDict2[int(docId)] += 1
	
	return postingsLists

# The driver function for the program which creates a pickle of postingsList dictionary
if __name__ == '__main__':
	if len(sys.argv) > 1:
		dirName = sys.argv[1]
	else:
		print "Usage: \n$ python PostingsList.py [DirName]"
		sys.exit(0)
	
	# Store the postings list dictionary in a pickle file.
	with open('corpus.pickle', 'wb') as f:
		pickle.dump(postingsList(dirName), f)
