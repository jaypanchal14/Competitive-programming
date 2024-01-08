import matplotlib.pyplot as plt
import numpy as np

#1) Normal X-Y Axis scatter plot showing just the dots for the pair (x,y)
def drawScatterPlot():
    x_data = np.random.random(10) * 10
    y_data = np.random.random(10) * 10
    plt.scatter(x_data, y_data, c="#00f", marker="X")
    plt.show()

#drawScatterPlot()

#2) Line-Plotting
def drawLinePlot():
    x = [1,2,3,4,5,6]
    y = [10,5,9,2,3,8]
    plt.plot(x,y, c="#000", linestyle="--")
    plt.show()

#drawLinePlot()

#3) Bar-graph
def drawBarGraph():
    x = [1,2,3,4,5,6]
    y = [10,5,9,2,3,8]
    plt.bar(x,y)
    plt.show()

#drawBarGraph()

#4) Histogram
def drawHistogram():
    x = np.random.normal(10, 1.5, 100)
    plt.hist(x)
    plt.show()
#drawHistogram()

import nltk
from nltk.corpus import stopwords

from nltk.sentiment import SentimentIntensityAnalyzer
from nltk.stem import WordNetLemmatizer


eng_stop_words = set(stopwords.words('english'))

sia = SentimentIntensityAnalyzer()

def get_lem_sentence(paragraph):
    lemmatizer = WordNetLemmatizer()
    lem_sentences = nltk.sent_tokenize(paragraph)
    for i in range(len(lem_sentences)):
        words = nltk.word_tokenize(lem_sentences[i])
        words = [lemmatizer.lemmatize(word) for word in words if word not in eng_stop_words]
        lem_sentences[i] = ' '.join(words)
    return lem_sentences


stat = "i read this 2 days ago.... and remember nothing from it \n disappointing"
stat = get_lem_sentence(stat)

print(sia.polarity_scores(stat[0]))