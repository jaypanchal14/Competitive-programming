#include<iostream>
#include<limits.h>

using namespace std;

/*
Description:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
Example:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        get(root, ans);
        return ans;
    }

    int get(TreeNode* root,int& ans){
        if(!root){
            return 0;
        }
        int l = max(0, get(root->left, ans));
        int r = max(0, get(root->right, ans));
        ans = max(ans, l+r+root->val);
        return max(l,r)+root->val;
    }
};