#include<vector>
#include<iostream>
#include<climits>
using namespace std;

/*
Description:
ou are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
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

    TreeNode* first = nullptr, *second = nullptr;
    TreeNode* pre;

    void recoverTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return;
        }
        pre = new TreeNode(INT_MIN);
        correct(root);
        swap(first->val, second->val);
    }

    void correct(TreeNode* root){
        if(!root){
            return;
        }
        correct(root->left);
        if(first == nullptr && root->val < pre->val){
            first = pre;
        }
        if(first != nullptr && root->val < pre->val){
            second = root;
        }
        pre = root;
        correct(root->right);
    }

};