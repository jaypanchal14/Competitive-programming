#include<iostream>
#include<vector>

using namespace std;

/*
Description:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

struct Node{
    Node* next[26] = {NULL};
    bool end = false;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Node *root = new Node;
        root->end = false;
        Node* tmp;
        //Building trie
        for(string& s : wordDict){
            tmp = root;
            for(char& c : s){
                if(tmp->next[c-'a'] == NULL){
                    tmp->next[c-'a'] = new Node;
                }
                tmp = tmp->next[c-'a'];
            }
            tmp->end = true;
        }
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        //searching in the trie
        for(int i=0; i<n; i++){
            if(dp[i]){
                tmp = root;
                for(int k=i; k<n; k++){
                    if(tmp->next[s[k]-'a'] == NULL){
                        break;
                    }
                    tmp = tmp->next[s[k]-'a'];
                    if(tmp->end){
                        dp[k+1] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};