#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Description:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations (from the key-pad mobile phones) 
that the number could represent. Return the answer in any order.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

class Solution {
public:

    void get(string& digits, string s, int i, vector<string>& ans, unordered_map<char,vector<char>>& m){
        if(i==digits.size() && s.size()>0){
            ans.push_back(s);
            return;
        }
        //cout<<"s:"<<s<<", index:"<<i<<endl;
        
        for(char c : m[digits[i]]){
            //cout<<c<<" ";
            s.push_back(c);
            get(digits, s, i+1, ans, m);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string> ans;
        unordered_map<char,vector<char>> v;
        v['2'] = {'a','b','c'};
        
        v['3'] = {'d','e','f'};
        v['4'] = {'g','h','i'};
        v['5'] = {'j','k','l'};
        v['6'] = {'m','n','o'};
        v['7'] = {'p','q','r','s'};
        v['8'] = {'t','u','v'};
        v['9'] = {'w','x','y','z'};
        
        get(digits, "", 0, ans, v);
        return ans;
    }
};

/*
class Solution {
public:
    void generateCombos(int idx, string& digits, string& temp, vector<string>& sol, vector<string>& charMap){
        if(idx==digits.length()){
            if(temp.length()) sol.push_back(temp);
            return;
        }

        int num=digits[idx]-'0';
        string str=charMap[num];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            generateCombos(idx+1, digits, temp, sol, charMap);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> sol;
        vector<string> charMap={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        generateCombos(0, digits, temp, sol, charMap);
        return sol;
    }
};
*/