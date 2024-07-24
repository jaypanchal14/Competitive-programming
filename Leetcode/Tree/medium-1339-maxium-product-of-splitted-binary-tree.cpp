#include <iostream>
using namespace std;

/*
Description:
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. 
Since the answer may be too large, return it modulo 109 + 7.
Note that you need to maximize the answer before taking the mod and not after taking it.
Example:
Input: root = [1,2,3,4,5,6]
Output: 110
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

    void dfs(TreeNode* root, int& sum){
        if(!root){
            return;
        }
        sum += root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    long long get(TreeNode* root, int& sum, long long& ans){
        if(!root){
            return 0;
        }
        long long cur = root->val + get(root->left, sum, ans) + get(root->right, sum, ans);
        long long a = cur * (sum-cur);
        if(ans < a){
            ans = a;
        }
        return cur;
    }

    int maxProduct(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        long long ans = 0;
        get(root, sum, ans);
        return static_cast<int>(ans % 1000000007);
    }
};