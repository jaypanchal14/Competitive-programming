#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;

/*
Description :
In English, we have a concept called root, which can be followed by some other word to form another longer word - 
let's call this word derivative. 
For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, 
replace all the derivatives in the sentence with the root forming it. 
If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.

Example : 
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
*/

struct Trie{
    Trie* edge[26] = {nullptr};
    bool end_of_word = false;
};

class Solution {
public:

    Trie* root;

    void insert(string word){
        Trie* head = root;
        int i;
        for(char& c : word){
            i = c-'a';
            if(!head->edge[i]){
                head->edge[i] = new Trie();
            }
            head = head->edge[i];
        }
        head->end_of_word = true;
    }

    string search(string& word){
        string tmp = "";
        Trie* head = root;
        int i;
        for(char& c : word){
            i = c-'a';
            if(!head->edge[i]){
                return word;
            }
            tmp.push_back(c);
            head = head->edge[i];
            if(head->end_of_word){
                return tmp;
            }
        }
        return word;
    }

    string replaceWordsWithTrie(vector<string>& d, string s){
        root = new Trie();

        //Build a trie using dictionary
        for(string& word : d){
            insert(word);
        }

        //Traverse each word of s and find matched prefix from trie
        string ans = "", tmp;
        stringstream ss(s);
        while(ss >> tmp){
            ans.append(search(tmp) + " ");
        }
        ans.pop_back();
        return ans;
    }

    string replaceWords(vector<string>& d, string s) {
        unordered_map<char, vector<string>> m;
        sort(d.begin(), d.end());
        for(int i=0; i<d.size(); i++){
            m[d[i][0]].push_back(d[i]);
        }
        string ans = "";
        int i = 0;
        string tmp = "";
        bool found = false;
        while(i<s.size()){
            if(m.find(s[i])!=m.end()){
                //cout<<"if at:"<<i<<endl;
                while(i<s.size() && s[i]!=' '){
                    tmp.push_back(s[i++]);
                }
                for(string& ss : m[tmp[0]]){
                    // cout<<"tmp:"<<tmp<<", ss:"<<ss<<endl;0
                    if(tmp.substr(0,ss.size()) == ss){
                        found = true;
                        ans.append(ss+" ");
                        break;
                    }
                }
                if(!found){
                    ans.append(tmp+" ");
                }
                found = false;
            }else{
                //cout<<"else at:"<<i<<endl;
                while(i<s.size() && s[i]!=' '){
                    tmp.push_back(s[i++]);
                }
                ans.append(tmp+" ");
            }
            i++;
            tmp = "";
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> dict = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout<<"Output with Trie: "<<s.replaceWordsWithTrie(dict, sentence)<<endl;
    // cout<<"Output: "<<s.replaceWords(dict, sentence)<<endl;
    return 0;
}