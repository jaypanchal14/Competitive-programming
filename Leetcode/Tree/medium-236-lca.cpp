#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
Description:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
Example:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
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

    //For both binary tree and binary search tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r){
            return root;
        }else if(l){
            return l;
        }else if(r){
            return r;
        }else{
            return NULL;
        }
    }

    //For binary search tree
    TreeNode* lowestCommonAncestorOfBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxi = max(p->val, q->val);
        int mini = min(p->val, q->val);
        while(root){
            if(root->val > maxi){
                root = root->left;
            }else if(root->val < mini){
                root= root->right;
            }else{
                return root;
            }
        }
        return NULL;
    }
};