#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

/*
Objective :
Remove the adjacent duplicate characters and return the final string.
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move. 
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/

string removeDuplicates(string s) {
    int i = 1;
    int size = s.size();
    while(i<size){
        if(s[i] == s[i-1]){
            s.erase(i-1,2);
            i--;
        }else{
            i++;
        }
    }
    return s;
}

string removeDuplicatesExtraString(string s) {
    int i = 0;
    string tmp = "";
    int size = s.size();
    while(i<size){
        if(tmp.size()>0 && tmp[tmp.size()-1] == s[i]){
            tmp.pop_back();            
        }else{
            tmp.push_back(s[i]);
        }
        i++;
    }
    return tmp;
}

string removeDuplicatesUsingStack(string s){
    stack<int> st;
    int i = 0;
    st.push(s[i++]);
    int size = s.size();
    while(i<size){
        if(s[i] == st.top()){
            i++;
            st.pop();
        }else{
            st.push(s[i++]);
        }
    }
    string tmp;
    while(!st.empty()){
        tmp.push_back(st.top());
        st.pop();
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main(){

    string s1;
    cout<<"Enter first string: ";
    getline(cin, s1);
    // string result = removeDuplicates(s1);
    string result = removeDuplicatesUsingStack(s1);
    cout<<"Final result is: "<<result<<endl;
    return 0;
}