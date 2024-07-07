#include<iostream>
#include<climits>
using namespace std;

/*
Description:
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.

Constraint : A subtree must include all of its descendants.

Example:
Input: [10,5,15,1,8,null,7]

   10
   / \
  5  15
 / \   \
1   8   7

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

    int ans;

    //pair<int, pair<int,int>> : {cur_largest, {root-mini, root=maxi}}

    pair<int, pair<int,int>> count(TreeNode* root){
        if(!root){
            return {0,{INT_MAX, INT_MIN}};
        }

        pair<int, pair<int,int>> l = count(root->left);
        pair<int, pair<int,int>> r = count(root->right);
        if(root->val > (l.second.second) && root->val < (r.second.first)){
            ans = max(ans, l.first + r.first + 1);
            return {l.first + r.first + 1, {max(l.second.second, root->val), min(root->val, r.second.first)}};
        }

        //Due to constraint
        return {0,{INT_MIN, INT_MAX}};
    }

};

int main(){

    Solution s;
    s.ans = 0;
    //[5,2,4,1,3]
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    pair<int, pair<int,int>> ans = s.count(root);
    cout<<"Largest BST is of size: "<<s.ans;
    return 0;
}