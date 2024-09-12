#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
Description:
Given the root of a binary tree, return the different top, right, bottom view of the tree.
Example:
1) For Top side view
Input: root = [1,2,3,4,5,6,7,8,null,9,null,null,10]
Output: [8, 4, 2, 1, 3, 7]
2) For Bottom view
Input: root = [1,2,3,4,5,6,7,8,null,9,null,null,10]
Output: [8, 4, 9, 6, 10, 7]

1) For left side view
Input: root = [1,2,3,4,5,6,7,8,null,9,null,null,10]
Output: [1, 2, 4, 8]
2) For right view
Input: root = [1,2,3,4,5,6,7,8,null,9,null,null,10]
Output: [1, 3, 7, 10]
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

    vector<int> topView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        map<int, int> m;
        q.push({root, 0});
        TreeNode* node; 
        int col;
        while(!q.empty()){
            node = q.front().first;
            col = q.front().second;
            q.pop();
            if(m.find(col)==m.end()){
                m[col] = node->val;
            }
            if(node->left){
                q.push({node->left, col-1});
            }
            if(node->right){
                q.push({node->right, col+1});
            }
        }
        vector<int> ans;
        for(auto& p : m){
            ans.push_back(p.second);
        }
        return ans;
    }

    vector<int> bottomView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        map<int, int> m;
        q.push({root, 0});
        TreeNode* node; 
        int col;
        while(!q.empty()){
            node = q.front().first;
            col = q.front().second;
            q.pop();
            m[col] = node->val;
            if(node->left){
                q.push({node->left, col-1});
            }
            if(node->right){
                q.push({node->right, col+1});
            }
        }
        vector<int> ans;
        for(auto& p : m){
            ans.push_back(p.second);
        }
        return ans;
    }

    vector<int> leftSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        int index = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        bool first = true;
        while(!q.empty()){
            ans.emplace_back(0);
            for(int i=q.size();i>0; i--){
                tmp = q.front();
                q.pop();
                if(first){
                    ans[index] = tmp->val;
                    first = false;
                }
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            index++;
            first = true;
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        //Recursive
        //getRight(root, ans, 0);

        //Iterative
        int index = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        while(!q.empty()){
            ans.emplace_back(0);
            for(int i=q.size();i>0; i--){
                tmp = q.front();
                q.pop();
                ans[index] = tmp->val;
                if(tmp->left){
                q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            index++;
        }
        return ans;
    }

    void getRight(TreeNode* root, vector<int>& ans, int level){
        if(!root){
            return;
        }
        if(level == ans.size()){
            ans.emplace_back(root->val);
        }
        getRight(root->right, ans, level+1);
        getRight(root->left, ans, level+1);
    }
};

int main(){

    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->right->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);


    vector<int> ans = s.topView(root);
    cout<<"Top view: ";
    for(int& a : ans){
        cout<<a<<", ";
    }
    cout<<endl;
    ans = s.bottomView(root);
    cout<<"Bottom view: ";
    for(int& a : ans){
        cout<<a<<", ";
    }
    cout<<endl;
    ans = s.leftSideView(root);
    cout<<"Left view: ";
    for(int& a : ans){
        cout<<a<<", ";
    }
    cout<<endl;
    ans = s.rightSideView(root);
    cout<<"Right view: ";
    for(int& a : ans){
        cout<<a<<", ";
    }
    cout<<endl;
    return 0;
}