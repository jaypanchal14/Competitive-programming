#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

/*
Description : Number of operations needed to balance the strings of parenthesis.
*/

int get(string str){
    stack<char> s;
    for(char c : str){
        if(s.empty() || c=='{'){
            s.push(c);
        }else{
            if(s.top()=='{'){
                s.pop();
            }else{
                s.push(c);
            }
        }
    }
    if(s.size()==0){
        return 0;
    }
    else if(s.size()%2==1){
        return -1;
    }else{
        int ans = 0;
        int close=0, open=0;
        string ss ="";
        while(!s.empty()){
            ss.push_back(s.top());
            s.pop();
        }
        //reverse(ss.begin(),ss.end());
        int pos = ss.find('{');
        int size = ss.size();
        if(pos==size-1 || pos==size/2 || pos == string::npos){
            ans = size/2;
        }else{
            ans = (size+2)/2;
        }
        return ans;
    }
}

int main(){
    string str = "}}}{";
    cout<<get(str);
    /*
    {{{{
    }{{{
    }}}{{{{{
    }}{{
    }}}{
    }}}}
    */
    return 0;
}