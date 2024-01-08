# NLP : Natural language processing

#----------------------------------------------------------------------------------------------------------------------------
# 1) Tokenization : To create token from  given string-variable (storing multiple sentences)
#     We can either create token for each sentences. 
#     or
#     We can either create token for each words. 

# 2) Stemming / Lemmetization : Process of reducing given words to their stem-word.
# Example : finally, finalized, final -> final (stemmed word)

# Note : Stemming might give you meaningless stemmed word, whereas lemmetization focuses more on meaningful word.
#----------------------------------------------------------------------------------------------------------------------------
# We can perform text pre-processing with the help of 'nltk' library.

#----------------------------------------------------------------------------------------------------------------------------
#Once we have got all the sentences after tokenizing them, we need their vector. Basically, we need to convert words to vector, as
#ML models can only interpret numerical data precisely.

# (1) Most basic method is "Bag Of Words" (BOW)
# It can be either binary BOW or non-binary BOW.
# Binary BOW: it will just mark whether the word is present or not
# Non-binary BOW : it will store the count of word present in the sentence.
#----------------------------------------------------------------------------------------------------------------------------
"""
Important Note before running this code
download required data/library from nltk explicitly

//This will download required tokenizer and stopwords
nltk.download('punkt')
nltk.download('wordnet')
"""

import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer
import re
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfVectorizer
from gensim.models import Word2Vec


eng_stop_words = set(stopwords.words('english'))
paragraph = "A paragraph is a series of sentences that are organized and coherent, and are all related to a single topic. Almost every piece of writing you do that is longer than a few sentences should be organized into paragraphs."

#----------------------------------------------------------------------------------------------------------------------------
#(1) tokenization with stemming

def get_stem_sentence(paragraph):
    stemmer = PorterStemmer()
    stem_sentences = nltk.sent_tokenize(paragraph)
    for i in range(len(stem_sentences)):
        words = nltk.word_tokenize(stem_sentences[i])
        words = [stemmer.stem(word) for word in words if word not in eng_stop_words]
        stem_sentences[i] = ' '.join(words)
    return stem_sentences
#print("With Stemming: ",get_stem_sentence(paragraph)[0])

#----------------------------------------------------------------------------------------------------------------------------
#(2) tokenization with lemmetization

def get_lem_sentence(paragraph):
    lemmatizer = WordNetLemmatizer()
    lem_sentences = nltk.sent_tokenize(paragraph)
    for i in range(len(lem_sentences)):
        words = nltk.word_tokenize(lem_sentences[i])
        words = [lemmatizer.lemmatize(word) for word in words if word not in eng_stop_words]
        lem_sentences[i] = ' '.join(words)
    return lem_sentences
# print("With Lemmetization: ",get_lem_sentence(paragraph)[0])


#----------------------------------------------------------------------------------------------------------------------------
#(3) Bag of Words or Count-vectorization

def get_processed_sentences(paragraph):
    lemmatizer = WordNetLemmatizer()
    bwsentence = nltk.sent_tokenize(paragraph)

    #To store processed tokens for each sentence
    corpus = []
    for i in range(len(bwsentence)):
        review = re.sub('[^a-zA-Z]',' ',bwsentence[i])
        review = review.lower()
        
        # Before splitting, we can also call word_tokenize method to get list of words
        #words = nltk.word_tokenize(review)
        
        words = review.split()
        # In case of stemming
        #words = [stemmer.stem(word) for word in words if word not in eng_stop_words]
        
        # In case of lemmetizing
        words = [lemmatizer.lemmatize(word) for word in words if word not in eng_stop_words]
        review = ' '.join(words)
        corpus.append(review)
    return corpus
#print("Tokenized sentences: ",get_processed_sentences(paragraph)[0])


def get_bag_of_words(corpus):
    vectorizer = CountVectorizer()
    cv_array = vectorizer.fit_transform(corpus).toarray()
    # print("With Bag-of-word:\n", cv_array)
    return cv_array
#corpus = get_processed_sentences(paragraph)
#print("Bag-Of-Words : \n",get_bag_of_words(corpus))

#----------------------------------------------------------------------------------------------------------------------------
#(4) TF-IDF : Term Frequency and Inverse document frequency
# TF : number of repeative words in a sentence / total words
# IDF : log(total sentences / number of sentences containing any word)

#TF-TDF : TF * IDF

def get_TF_IDF(corpus):
    tf_idf = TfidfVectorizer()
    tf_array = tf_idf.fit_transform(corpus).toarray()
    #print('With TF-IDF \n',tf_array)
    return tf_array
#corpus = get_processed_sentences(paragraph)
#print("TF-IDF : \n",get_TF_IDF(corpus).shape)

#----------------------------------------------------------------------------------------------------------------------------
#(5)Word2Vec
# Technique to derive word associations from a given group of sentences.
def getWord2Ved(paragraph):
    text = re.sub(r'\[[0-9]*\]',' ',paragraph)
    text = re.sub(r'\s+',' ',text)
    text = text.lower()
    
    sentences = nltk.sent_tokenize(text)
    sentences = [nltk.word_tokenize(s) for s in sentences]
    sentences = [word for words in sentences for word in words if word not in eng_stop_words]

    #min_count : This parameter ignores all words with a total frequency lower than the specified value while training the model
    model = Word2Vec(sentences, min_count=1)
    #print(model.cum_table)

#getWord2Ved(paragraph)
#----------------------------------------------------------------------------------------------------------------------------

#   Project Help
#from sklearn.naive_bayes import CategoricalNB
#Naive bayes works very well with the NLP problems, check with it for a test. Try different models based on NB
#While doing text processing on reviews, select those features, having maximum occurence

#The used classifiers show substantial accuracy in predicting reader satisfaction. Among them, 
#the random forest classifier combined with the TF-IDF feature representation method exhibited the highest accuracy at 96.09%.
    
from nltk.sentiment import SentimentIntensityAnalyzer

sia = SentimentIntensityAnalyzer()

sent = "You are so negative"

print(sia.polarity_scores(sent))