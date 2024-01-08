import pandas as pd
import numpy as np

# df1 =  pd.DataFrame({'Apples':[1,3],'Bananas':[2,4]}, index=[1,2])
# print(df1.loc[1,:])

# y = df1["Apples"]
# print(y)

#a = np.array([[1,2,3,4,5,6]])
#w = np.array([[1,1,2,4,4,6]])

a = np.array([[1],[2],[3],[4],[5],[6]])
w = np.array([[1],[1],[2],[4],[4],[6]])

print(np.zeros_like())

# print(a.shape, w.shape, b.shape)
# loc and iloc, both only differs on how we perform indexing over the dataframe.
# iloc is based on normal indexing, starting from 0. iloc[:10] - > this will yield first 10 rows, index 0 to index 9
# loc is similar to iloc, but we can also search/filter it based on string value. loc[:10] -> will return 11 rows, from index 0 to index 10

# loc and iloc works on this paradigm : first get the rows, then search for column
#df1.loc[0,'Bananas'] -> first row, second string column
#df1.iloc[0,1] -> first row, first column
#print(df1['Apples'].value_counts())


# sr1 = pd.Series(['4 cups','1 cup','2 large','1 can'],index=['Flour','Milk','Eggs','Spam'],name='Dinner')
#print(sr1)

# To read from csv file, and giving 0th column as its index
#reviews = pd.read_csv('../input/wine-reviews/winemag-data_first150k.csv',index_col=0)

# To write it back to csv file
#df1.to_csv('<name-of-file>')

#To convert categorical data to numerical
#pd.get_dummies()


#Describe functions
# df1.describe()
# df1.Apples.describe()
# df1.Apples.mean()
# df1.Apples.unique()
# df1.Apples.value_counts()
