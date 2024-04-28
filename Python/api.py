from fastapi import FastAPI
from pydantic import BaseModel

class UserInput(BaseModel):
    operation : str
    x : float
    y : float

app = FastAPI()

def fib(n):   # return Fibonacci series up to n
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result

def calculator(operation, x, y):
    if(operation=='ADD'):
        return x + y
    elif(operation=='SUB'):
        return x-y
    elif(operation=='MUL'):
        return x*y
    elif(operation=='DIV'):
        if(y==0):
            return 0
        return x/y
    elif(operation=='MOD'):
        return x%y
    elif(operation=='FIB'):
        return fib(x)
    
# pip install "uvicorn[standard]"  -> for server
# pip install fastapi
# command to run : uvicorn FastApi:app 
# option to pass while running (if you want automatic reloading):  --reload

#curl -X POST -d '{"operation" : "FIB", "x" : 5, "y" : 10}' 'http://127.0.0.1:8000/calculate'
  

#swagger api : 
# http://127.0.0.1:8000/docs
# or
# http://127.0.0.1:8000/redoc

# you can try endpoints from the swagger api doc

@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.post("/calculate")
async def root(user_input: UserInput):
    return {"result": calculator(user_input.operation, user_input.x, user_input.y)}


