#include <iostream>
#include <queue>
#include<unordered_map>
using namespace std;

/*
Description:
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        //BFS approach
        long long ans = 1, index, l, r, mini;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        TreeNode* tmp;
        while(!q.empty()){
            l = q.front().second;
            r = q.back().second;
            ans = max(ans, r-l+1);
            for(int i=q.size(); i>0; i--){
                tmp = q.front().first;
                index = q.front().second - l;
                q.pop();
                if(tmp->left){
                    q.push({tmp->left, index*2+1});
                }
                if(tmp->right){
                    q.push({tmp->right, index*2+2});
                }
            }
        }
        return ans;

        /*
        //DFS two-pass approach (Inefficient)
        unordered_map<int, unsigned> mini, maxi;
        unsigned index = 0;
        get(root, index, 0, mini, maxi);
        unsigned ans = 1;
        check(root, 0, mini, maxi, ans);
        return ans;
        */
    }
    
    void check(TreeNode* r, int level, unordered_map<int,unsigned>& mini, unordered_map<int,unsigned>& maxi, unsigned& ans){
        if(!r){
            return;
        }
        ans = max(ans, maxi[level]-mini[level]+1);
        check(r->left, level+1, mini, maxi, ans);
        check(r->right, level+1, mini, maxi, ans);
    }
    
    void get(TreeNode* r, unsigned index, int level, unordered_map<int,unsigned>& mini, unordered_map<int,unsigned>& maxi){
        if(!r){
            return;
        }
        if(mini.count(level)==0){
           mini[level]=index; 
        }
        maxi[level] = index;
        get(r->left, index*2+1, level+1, mini, maxi);
        get(r->right, index*2+2, level+1, mini, maxi);
    }
    
};