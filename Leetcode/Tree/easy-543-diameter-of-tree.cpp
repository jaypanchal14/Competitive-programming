#include<iostream>

using namespace std;

/*
Description:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.
Example:
Input : [1,2,null,2,3,4,5,6,6,7,8,99,8]
Output : 5
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        get(root, ans);
        return ans;
    }

    int get(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }
        int l = get(root->left, ans);
        int r = get(root->right, ans);
        ans = max(ans, l+r);
        return max(l,r)+1;
    }
};