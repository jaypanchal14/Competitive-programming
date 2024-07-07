#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
Description:
Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, 
but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Example:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int target) {
        int ans = 0;
        vector<long> path;
        get(root, target, ans, path);
        return ans;
    }

    void get(TreeNode* root, int& target, int& ans, vector<long>& path){
        if(!root){
            return;
        }
        path.emplace_back(root->val);
        get(root->left, target, ans, path);
        get(root->right, target, ans, path);
        long sum = 0;
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i];
            if(sum==target){
                ans++;
            }
        }
        path.pop_back();
    }
};