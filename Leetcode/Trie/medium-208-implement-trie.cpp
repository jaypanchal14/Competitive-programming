#include<iostream>
#include<vector>
using namespace std;

/*
Description :
Implement the Trie class:
-Trie() Initializes the trie object.
-void insert(String word) Inserts the string word into the trie.
-boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
-boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
Example : 
Input ->
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output ->
[null, null, true, false, true, null, true]
*/

struct Node{
    Node* next[26] = {NULL};
    bool end;
};

class Trie {
public:

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        int i;
        for(char& c : word){
            i = c-'a';
            if(tmp->next[i] == NULL){
                tmp->next[i] = new Node();
            }
            tmp = tmp->next[i];
        }
        tmp->end = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        int i;
        for(char& c : word){
            i = c-'a';
            if(tmp->next[i] == NULL){
                return false;
            }
            tmp = tmp->next[i];
        }
        return tmp->end;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        int i;
        for(char& c : prefix){
            i = c-'a';
            if(tmp->next[i] == NULL){
                return false;
            }
            tmp = tmp->next[i];
        }
        return true;
    }
};