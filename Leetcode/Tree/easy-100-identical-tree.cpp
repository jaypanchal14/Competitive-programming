#include<iostream>

using namespace std;

/*
Description:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
Example:
Input: p = [1,2], q = [1,null,2]
Output: false
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if((!p && q) || (p && !q)){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        bool l = isSameTree(p->left, q->left);
        if(!l){
            return l;
        }
        return isSameTree(p->right, q->right);
    }
};