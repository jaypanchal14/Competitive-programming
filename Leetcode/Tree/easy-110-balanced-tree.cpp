#include<iostream>

using namespace std;

/*
Description:
Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is a binary tree in which 
the depth of the two subtrees of every node never differs by more than one.
Example:
Input: root = [3,9,20,null,null,15,7]
Output: true
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
    bool isBalanced(TreeNode* root) {
        int a = check(root);
        return a!=-1;
    }

    int check(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = check(root->left);
        if(l==-1){
            return -1;
        }
        int r = check(root->right);
        if(r==-1){
            return -1;
        }
        if(abs(l-r)>1){
            return -1;
        }
        return max(l,r)+1;
    }
};