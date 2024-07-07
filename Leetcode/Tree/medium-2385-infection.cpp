#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Description:
You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
-The node is currently uninfected.
-The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
Example:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
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

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> ss;
        buildMap(root, m, start);
        int ans = 0, tmp;
        queue<int> q;
        q.push(start);
        ss.insert(start);
        bool cc = false;
        while(!q.empty()){
            for(int i=q.size(); i>0; i--){
                tmp = q.front();
                q.pop();
                for(int& x : m[tmp]){
                    if(ss.count(x)==0){
                        cc = true;
                        q.push(x);
                        ss.insert(x);
                    }
                }
            }
            if(cc){
                ans++;
                cc = false;
            }
        }
        return ans;
    }


    void buildMap(TreeNode* root, unordered_map<int, vector<int>>& m, int s){
        queue<TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        // m[root->val] = {};
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp->left){
                m[tmp->val].emplace_back(tmp->left->val);
                m[tmp->left->val].emplace_back(tmp->val);
                q.push(tmp->left);
            }
            if(tmp->right){
                m[tmp->val].emplace_back(tmp->right->val);
                m[tmp->right->val].emplace_back(tmp->val);
                q.push(tmp->right);
            }
        }
    }
};