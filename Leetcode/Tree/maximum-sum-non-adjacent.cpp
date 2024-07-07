#include<iostream>
using namespace std;

/*
Description:
Given a binary tree, find the maximum-sum of nodes such that no two-nodes considered in finding the sum are adjacent.
Example:
Input: root = [1,2,3,4,null,5,6]
Output: 16

*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution{

public:

    int getSum(TreeNode* root){
        if(!root){
            return 0;
        }
        pair<int, int> ans = get(root);
        return max(ans.first,ans.second);
    }

    //pair<int,int> p contains first-> sum if current is included, second if not included

    pair<int, int> get(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        pair<int, int> l = get(root->left);
        pair<int, int> r = get(root->right);

        pair<int, int> ans;
        ans.first = root->val + l.second + r.second;
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        return ans;
    }
};