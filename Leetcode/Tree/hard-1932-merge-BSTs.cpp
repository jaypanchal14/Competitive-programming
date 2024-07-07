#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Description:
You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). 
Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:
-Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
-Replace the leaf node in trees[i] with trees[j].
-Remove trees[j] from trees.

Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, 
or null if it is impossible to create a valid BST.

Example:
Input: trees = [[2,1],[3,2,5],[5,4]]
Output: [3,2,5,1,null,4]
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
    TreeNode* canMerge(vector<TreeNode*>& t) {
        if(t.size()==1){
            return valid(t[0], 0, 100000)?t[0]:NULL;
        }
        TreeNode* root = NULL, *tmp = NULL;
        unordered_map<int, TreeNode*> m;
        for(int i=0; i<t.size(); i++){
            tmp = t[i];
            if(tmp->left){
                m[tmp->left->val] = tmp->left;
                
            }
            if(tmp->right){
                m[tmp->right->val] = tmp->right;
            }
        }

        //To check if there are two different possible root or not
        for(int i=0; i<t.size(); i++){
            tmp = t[i];
            if(m.count(tmp->val)){
                //Update the child to root
                m[tmp->val] = tmp; 
            }else if(root){
                return NULL;
            }else{
                root = tmp;
            }
        }
        if(!root)   return NULL;
        int c = 0;
        make(m, root, c);
        if(m.size()!=c) return NULL;
        return valid(root, 0,100000)?root:NULL;
    }

    bool valid(TreeNode* r, int mini, int maxi){
        if(!r)  return true;
        if(r->val <= mini || r->val >= maxi)    return false;
        return valid(r->left, mini, r->val) && valid(r->right, r->val, maxi); 
    }

    void make(unordered_map<int, TreeNode*>& m, TreeNode* &r, int& c){
        if(!r)  return;
        cout<<r->val<<endl;
        if(!r->left && !r->right && m[r->val]){
            //root is being updated here with the new root node from other bst
            r = m[r->val];
            m[r->val] = NULL;
            c++;
        }
        make(m, r->left, c);
        make(m, r->right, c);
    }
};