#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Description:
Given two integer arrays, where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal. 
Construct and return the binary tree.
Example:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for(int i=0; i<size; i++){
            map[inorder[i]] = i;
        }
        int index = size-1;
        return get(inorder, postorder, index, 0, index);
    }

    TreeNode* get(vector<int>& i, vector<int>& p, int& index, int start, int end){
        if(index == -1 || start>end){
            return NULL;
        }
        TreeNode* root = new TreeNode(p[index--]);
        int j = map[root->val];
        root->right = get(i, p, index, j+1, end);
        root->left = get(i, p, index, start, j-1);
        return root;
    }
};