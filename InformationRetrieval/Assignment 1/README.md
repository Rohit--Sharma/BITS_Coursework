#	INFORMATION RETRIEVAL
##	Text Based Search Engine

--------------------------------
###	Phase 1 (Indexing Component)
--------------------------------

**Tokenization**
    Tokenization is done using NLTK package. First we crawl through each file in the each directory recursively. Then open the files read each line and call word_tokenize() of NLTK to get tokens of the line. Next we store the tokens of each file in a list and map it to the file name in the dictionary.
    Reference - http://nlp.stanford.edu/software/tokenizer.shtml

**Normalization: Stemming**
    We normalize by stemming the tokens of the corpus. We call tokenization() to get the dictionary of tokens. We then call porters() method on each token to stem the tokens. Store them in a list corresponding to each files and map them to the file name.
    Reference - http://tartarus.org/~martin/PorterStemmer/
**Posting List Construction**
    Create a postings list for each term from stemmed terms by assigning frequency of it in each document. Store the postings list dictionary in pickle file.
    
-----------------------------------------------------
###	Phase 2 (Searching Component: Vector Space Model)
-----------------------------------------------------

**Inverse Document Frequency computation**
    idf(t) = log (N / df(t))
    
**Weights Computation**
    tf-idf(t,d) = tf(t,d) * idf(t)
    
**Cosine Score Computation**
    score(q,d) = v(q).v(d)
*Normalizing*
    score(q,d) / (|v(q)| * |v(d)|)
    
----------------------
**USAGE INSTRUCTIONS**
----------------------

**Requirements**
- Python 2.7
- nltk 
- punkt
- Atleast 1 GB Ram

**Included Files**
- PortersStemmer.py
- PostingsList.py
- VectorSpaceModel.py

**Corpora**
- All the files present in "20_newsgroups" directory

*Step-1*
$ python PostingsList.py 20_newsgroups
- Produces "corpus.pickle" file which is the binary representation of postingsList dictionary

*Step-2*
$ python VectorSpaceModel.py 19987
- The pickle file of step-1 should be in the same directory as the source file.
- After executing, enter queries to search when prompted.

-----------
**CONTACT**
-----------

Any queries can be addressed to _f2012050@hyderabad.bit-pilani.ac.in_
