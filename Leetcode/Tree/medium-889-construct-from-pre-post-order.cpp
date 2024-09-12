#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

/*
Description:
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Example:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
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

    unordered_map<int, int> map;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int size = preorder.size();
        for(int i=0; i<size; i++){
            map[postorder[i]] = i;
        }
        int index = 0;
        return get(preorder, postorder, index, 0, size-1);
    }

    TreeNode* get(vector<int>& pre, vector<int>& post, int& index, int start, int end){
        if(index == pre.size() || start>end){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[index++]);
        if(start==end){
            return root;
        }
        int j = map[pre[index]];
        root->left = get(pre, post, index, start, j);
        root->right = get(pre, post, index, j+1, end-1);
        return root;
    }
};