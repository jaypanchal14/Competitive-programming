#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
Description:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root); 
        vector<vector<int>> ans;
        int index = 0;
        TreeNode* tmp;
        while(!q.empty()){
            ans.push_back({});
            for(int i=q.size(); i>0; i--){
                tmp = q.front();
                q.pop();
                ans[index].push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            index++;
        }
        for(int i=0; i<index; i++){
            if(i%2==1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};