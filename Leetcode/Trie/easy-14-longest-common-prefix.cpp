#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example:
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

struct Node{
    Node* next[26] = {NULL};
    int child;
    bool end;
};
class Solution {
public:

    Node* root;

    Solution(){
        root = new Node();
        root->child = 0;
        root->end = false;
    }

    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }

    string longestCommonPrefixWithTrie(vector<string>& strs) {
        string ans = "";
        Node* tmp = NULL;
        int k;
        for(int i=0; i<strs.size(); i++){
            if(strs[i].size()==0){
                return "";
            }
            tmp = root;
            for(char& c : strs[i]){
                k = c-'a';
                if(tmp->next[k] == NULL){
                    tmp->next[k] = new Node();
                    (tmp->child)++;
                }
                tmp = tmp->next[k];
            }
            tmp->end = true;
        }
        get(root, ans);
        return ans;
    }

    void get(Node* n, string& ans){
        if(!n || n->child > 1){
            return;
        }
        int index = -1, c = 0;
        for(int i=0; i<26; i++){
            if(n->next[i]){
                c++;
                if(index == -1){
                    index = i;
                }
            }
        }
        if(c==0 || c > 1){
            return;
        }
        ans.push_back('a'+index);
        n = n->next[index];
        if(n->end){
            return;
        }
        get(n, ans);
    }
};