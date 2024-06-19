#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/*
Description:
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column.
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
Example:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {{root->val}};
        }
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> m;
        get(root, m , 0, 0);
        vector<int> t;
        for(auto& p : m){
            sort(p.second.begin(), p.second.end(), [&](pair<int,int>& a, pair<int,int>& b){
                if(a.first==b.first){
                    return a.second < b.second;
                }
                return a.first<b.first;
            });
            t = {};
            for (auto& x : p.second) {
                t.push_back(x.second);
            }
            ans.push_back(t);
        }
        return ans;
    }

    void get(TreeNode* r, map<int, vector<pair<int,int>>>& m, int col, int row){
        if(!r){
            return;
        }
        m[col].push_back({row, r->val});
        get(r->left, m , col-1, row+1);
        get(r->right, m , col+1, row+1);
    }
};