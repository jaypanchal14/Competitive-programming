#include<vector>
#include<iostream>
#include<string>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr){}
    Node(int v, Node* l, Node* r): val(v), left(l), right(r){}
};

/*
Que-1 : Leetcode-250 (Count Univalue Subtrees)
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.
*/

bool dfs(Node* root, int& ans){
    if(!root){
        return true;
    }
    bool l = dfs(root->left, ans);
    bool r = dfs(root->right, ans);
    if(!l || !r){
        return false;
    }
    int a = root->left ? root->left->val : root->val;
    int b = root->right ? root->right->val : root->val;
    if(a==b && a==root->val){
        ans++;
        return true;
    }
    return false;
}

int getCount(Node* root){
    if(!root){
        return 0;
    }
    int ans = 0;
    dfs(root, ans);
    return ans;
}

/*
Que-2 : Lexicographically rank of the string (all characters are unique)
*/
int getRank(string s){
    int n = s.size(), count;
    if(n==1){
        return 1;
    }
    vector<int> fact(n+1,1);
    for(int i=2; i<=n; i++){
        fact[i] = fact[i-1]*i;
    }
    //Logic : fixing ith character, and finding count of smaller permutations than current
    int ans = 1;
    for(int i=0; i<n; i++){
        count = 0;
        for(int j=i+1; j<n; j++){
            if(s[i] > s[j]){
                count++;
            }
        }
        ans += count*fact[n-i-1];
    }
    return ans;
}

/*
Que-3 : Maximum path sum, leetcode 124 (Inside folder - Leetcode/Tree)
*/