#include<iostream>
#include<queue>
using namespace std;

/*
Description:
Given the root of a binary tree, return the boundaries elements starting from root in anti-clockwise direction.
Example:
Input : [1,2,2,3,4,4,3,11,null,5,null,null,5]
Output : [1,2,3,11,5,5,3,2]
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

    vector<int> getBoundary(TreeNode* root) {        
        if(!root){
            return {};
        }
        vector<int> ans;
        ans.emplace_back(root->val);
        getLeftSide(root->left, ans);
        getLeaves(root->left, ans);
        getLeaves(root->right, ans);
        getRightSide(root->right, ans);
        return ans;
    }

    void getLeftSide(TreeNode* r, vector<int>& ans){
        if(!r || (!r->left && !r->right)){
            return;
        }
        
        ans.emplace_back(r->val);
        if(r->left){
            getLeftSide(r->left, ans);
        }else{
            getLeftSide(r->right, ans);
        }
    }

    void getLeaves(TreeNode* r, vector<int>& ans){
        if(!r){
            return;
        }
        if(!r->left && !r->right){
            ans.emplace_back(r->val);
            return;
        }
        getLeaves(r->left, ans);
        getLeaves(r->right, ans);
    }

    void getRightSide(TreeNode* r, vector<int>& ans){
        if(!r || (!r->left && !r->right)){
            return;
        }
        if(r->right){
            getRightSide(r->right, ans);
        }else{
            getRightSide(r->left, ans);
        }
        ans.emplace_back(r->val);
    }
};

int main(){

    Solution s;
    //[1,2,2,3,4,4,3,11,null,5,null,null,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(11);
    root->left->right->left = new TreeNode(5);
    root->right->left->right = new TreeNode(5);


    vector<int> ans = s.getBoundary(root);
    cout<<"Boundary: ";
    for(int& a : ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}