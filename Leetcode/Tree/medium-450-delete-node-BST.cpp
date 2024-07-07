#include<iostream>

using namespace std;

/*
Description:
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Example:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
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

    TreeNode* pre(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }

    TreeNode* suc(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    /*
    Logic : We need to update the pointers after deleting the found node(if exists), so we call recusively.
    */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            //found
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(!root->left || !root->right){
                return root->left ? root->left : root->right;
            }
            TreeNode* ss = suc(root->right);
            root->val = ss->val;
            root->right = deleteNode(root->right, ss->val);
        }
        return root;
    }
};