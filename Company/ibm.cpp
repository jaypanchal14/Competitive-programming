#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

/*
Que : Given vector of string (str), check whether it is balanced or not. A string is made up of only '<' or '>' character.
A string is balanced if every '<' is followed by '>'.
Replace operation : replace '>' with "<>", count as 1 replace operation.
Then we have a list of integers (limits), of same size as str.
limits[i] = can be any non-negative integer, which conveys how many maximum replace operation can be performed.
*/

int check(string s, int limit){
    stack<char> st;
    for(char& c : s){
        if(st.empty() || c=='<'){
            st.push(c);
        }else if(st.top()=='<'){
            st.pop();
        }else{
            st.push(c);
        }
    }
    if(st.empty()){
        return 1;
    }
    string tmp = "";
    while(!st.empty()){
        tmp.push_back(st.top());
        st.pop();
    }
    reverse(tmp.begin(), tmp.end());
    size_t pos = tmp.find('<');
    if(pos != string::npos){
        return 0;
    }else{
        if(tmp.size() > limit){
            return 0;
        }else{
            return 1;
        }
    }
}

int main(){
    vector<string> str = {"<><>",">>"};
    vector<int> limits = {1,2};
    for(int i = 0; i < str.size(); i++){
        cout<<check(str[i], limits[i])<<" ";
    }
    return 0;
}