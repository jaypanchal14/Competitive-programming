'''
#Below code will enable interactive tables, a colab feature
from google.colab import data_table

data_table.enable_dataframe_formatter()
'''

#read from csv file  in Google Colab
def read_csv(file_path):
    """Reads a CSV file from the given path and returns it as a pandas DataFrame."""
    
    #importing necessary libraries
    import pandas as pd
    import os
  
    #check if the file exists in the specified location 
    if not os.path.isfile(file_path):
        raise FileNotFoundError("The provided file path does not exist.")
        
    #reading the csv file
    df = pd.read_csv(file_path)
      
    return df

import string
text = "in my year, i blew away."

print(text.translate(str.maketrans('', '', string.punctuation)))