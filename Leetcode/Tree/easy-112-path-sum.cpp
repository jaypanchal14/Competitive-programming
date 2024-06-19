#include<iostream>

using namespace std;

/*
Description:
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
Example:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
            return target==root->val;
        }
        if(hasPathSum(root->left, target-root->val)){
            return true;
        }
        return hasPathSum(root->right, target-root->val);
    }
        
};