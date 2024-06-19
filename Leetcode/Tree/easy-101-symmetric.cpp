#include<iostream>
#include<queue>
using namespace std;

/*
Description:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example:
Input : [1,2,2,3,4,4,3,11,null,5,null,null,5]
Output : false
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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }

        //Recursive
        //return check(root->left, root->right);

        //Iterative
        TreeNode *l, *r; 
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while(!q.empty()){
            l = q.front().first;
            r = q.front().second;
            q.pop();
            if(l && r){
                if(l->val!=r->val){
                    return false;
                }
                q.push({l->left, r->right});
                q.push({l->right, r->left});
                continue;
            }
            if(!l && !r){
                continue;
            }
            return false;
        }
        return true;
    }
    //Recursive
    bool check(TreeNode* l, TreeNode* r){
        if(!l && !r){
            return true;
        }
        if((l && !r) || (!l && r) || (l->val!=r->val)){
            return false;
        }
        return check(l->left, r->right) && check(l->right, r->left); 
    }
};