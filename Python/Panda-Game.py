import pandas as pd

df1 =  pd.DataFrame({'Apples':[30],'Bananas':[21]}, index=[1,2])
print(df1,'\n')

sr1 = pd.Series(['4 cups','1 cup','2 large','1 can'],index=['Flour','Milk','Eggs','Spam'],name='Dinner')
print(sr1)

# To read from csv file, and giving 0th column as its index
#reviews = pd.read_csv('../input/wine-reviews/winemag-data_first150k.csv',index_col=0)

# To write it back to csv file
#df1.to_csv('<name-of-file>')