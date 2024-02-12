#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Description :
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        string tmp;
        for(int i=0; i<strs.size(); i++){
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(m.find(tmp)!=m.end()){
                ans[m[tmp]].push_back(strs[i]);
            }else{
                m[tmp] = m.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};