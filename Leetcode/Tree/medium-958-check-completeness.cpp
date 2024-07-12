#include<iostream>

using namespace std;
/*
Description:
Given the root of a binary tree, determine if it is a complete binary tree.
In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
Example:
Input: root = [1,2,3,4,5,null,7]
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

    int get(TreeNode* root){
        if(!root)   return 0;
        return 1+get(root->left)+get(root->right);
    }

    bool isCompleteTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return true;
        }
        int count = get(root);
        int i = 0;
        return check(root, i, count);
    }

    bool check(TreeNode* root, int i, int count){
        if(!root)   return true;
        if(i>=count) return false;
        return check(root->left, 2*i+1, count) && check(root->right, 2*i+2, count);
    }
};