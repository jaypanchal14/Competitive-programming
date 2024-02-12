#include <iostream>
using namespace std;

/*
Description :
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

Input: s = "abc", t = "ahbgdc"
Output: true

Input: s = "axc", t = "ahbgdc"
Output: false
*/

bool isSubsequence(string s, string t){
    int is = s.size(), ts = t.size();
    if (ts < is){
        return false;
    }
    /*int i = 0, j = 0;
    while(i<ts && j<ts){
        if(s[i] == t[j++]){
            i++;
        }
    }
    return i == is;
    */
    int count = 0;
    for (int i = 0; i < ts && count < is; i++){
        if (s[count] == t[i]){
            count++;
        }
    }
    return count == is;
}

int main(){

    string s = "thereby";
    string t = "forthereorby";
    cout << isSubsequence(s, t);
    return 0;
}