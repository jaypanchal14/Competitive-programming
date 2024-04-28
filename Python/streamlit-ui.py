import streamlit as st
import json
import requests


# To run the file
# streamlit run --server.headless true streamlit-ui.py


st.title('Calculator App')

#Taking user requests
option = st.selectbox('Select an operation', ('ADD', 'SUB', 'MUL', 'DIV', 'MOD', 'FIB'))

st.write('')
st.write('Select numbers')

# write a code to take input from the user, if the operation if FIB, only display one input field and if not, display two input fields 

x = st.number_input("First number")
y = st.number_input("Second number")

inputs = {"operation":option, "x":x, "y":y}

if st.button('Calculate'):
    res = requests.post(url='http://127.0.0.1:8000/calculate', data=json.dumps(inputs))
    st.subheader(f"RESPONSE from API: {res.text}")