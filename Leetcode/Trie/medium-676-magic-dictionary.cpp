#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
Description :

Example:
Design a data structure that is initialized with a list of different words. Provided a string,
you should determine if you can change exactly one character in this string to match any word in the data structure.
-Implement the MagicDictionary class:
-MagicDictionary() Initializes the object.
-void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
-bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
Input ->
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output ->
[null, null, false, true, false, false]
*/

struct Node{
    Node* next[26] = {NULL};
    bool end;
};

class MagicDictionary {
public:

    Node* root;
    vector<string> v;
    unordered_set<string> st;

    MagicDictionary() {
        root = new Node();
    }
    
    //Approach - (1) -> using trie for first building the dict and searching in the trie by DFS
    void buildDictWithTrie(vector<string> dict) {
        Node* tmp = NULL;
        int k;
        for(int i=0; i<dict.size(); i++){
            tmp = root;
            for(char& c : dict[i]){
                k = c-'a';
                if(tmp->next[k]==NULL){
                    tmp->next[k] = new Node();
                }
                tmp = tmp->next[k];
            }
            tmp->end = true;
        }
    }
    
    bool searchWithTrie(string search) {
        //Check for current index's different char, later check for correct char
        // flag == true -> i have already changed one char
        return get(search, 0, false, root);
    }

    bool get(string& s, int i, bool flag, Node* r){
        if(!r)  return false;
        if(i==s.size()) return r->end && flag;
        int k = s[i]-'a';
        if(flag){
            return get(s, i+1, flag, r->next[k]);
        }else{
            for(char c='a'; c<='z'; c++){
                if(c!=s[i] && get(s, i+1, true, r->next[c-'a'])){
                    return true;
                }
            }
            return get(s, i+1, flag, r->next[k]);
        }
    }

    //Approach - (2) -> Using vector 
    void buildDict(vector<string> dictionary) {
        v = dictionary;
        //Only if they ask wether specific word is present or not
        /*for (auto& word : dictionary) {
            st.insert(word);
        }*/
    }

    bool search(string s) {
        for (auto& word : v) {
            if (word.size() != s.size()) continue;
            
            int diffCount = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != s[i]) {
                    diffCount++;
                    if (diffCount > 1) break;
                }
            }
            
            if (diffCount == 1) return true;
        }
        return false;
    }
};