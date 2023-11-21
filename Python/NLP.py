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
eng_stop_words = set(stopwords.words('english'))

#(1) tokenization with stemming
from nltk.stem import PorterStemmer

stemmer = PorterStemmer()
paragraph = "A paragraph is a series of sentences that are organized and coherent, and are all related to a single topic. Almost every piece of writing you do that is longer than a few sentences should be organized into paragraphs."

stem_sentences = nltk.sent_tokenize(paragraph)
for i in range(len(stem_sentences)):
    words = nltk.word_tokenize(stem_sentences[i])
    words = [stemmer.stem(word) for word in words if word not in eng_stop_words]
    stem_sentences[i] = ' '.join(words)
print("With stemming:",stem_sentences[0])

#(2) tokenization with lemmetization
from nltk.stem import WordNetLemmatizer

lemmatizer = WordNetLemmatizer()

lem_sentences = nltk.sent_tokenize(paragraph)
for i in range(len(lem_sentences)):
    words = nltk.word_tokenize(lem_sentences[i])
    words = [lemmatizer.lemmatize(word) for word in words if word not in eng_stop_words]
    lem_sentences[i] = ' '.join(words)

print("With lemmetization:",lem_sentences[0])

#(3) Bag of Words or Count-vectorization
import re
from sklearn.feature_extraction.text import CountVectorizer

bwsentence = nltk.sent_tokenize(paragraph)

corpus = [] #To store processed tokens for each sentence

for i in range(len(bwsentence)):
    review = re.sub('[^a-zA-Z]',' ',bwsentence[i])
    review = review.lower()
    words = review.split()
    # In case of stemming
    #words = [stemmer.stem(word) for word in words if word not in eng_stop_words]
    
    # In case of lemmetizing
    words = [lemmatizer.lemmatize(word) for word in words if word not in eng_stop_words]
    review = ' '.join(words)
    corpus.append(review)

vectorizer = CountVectorizer()
cv_array = vectorizer.fit_transform(corpus).toarray()
print("With Bag-of-word:\n", cv_array)

#(4) TF-IDF : Term Frequency and Inverse document frequency
# TF : number of repeative words in a sentence / total words
# IDF : log(total sentences / number of sentences containing any word)

#TF-TDF : TF * IDF

from sklearn.feature_extraction.text import TfidfVectorizer
tf_idf = TfidfVectorizer()
tf_array = tf_idf.fit_transform(corpus).toarray()
print('With TF-IDF \n',tf_array)