#include<iostream>
#include<vector>

using namespace std;

/*
Morris algo for in-order traversal :      Time : O(n),   Space : O(1)
cur = root
while(root is not null)
    if left doesn't exist
        visit(cur)
        cur = cur -> right;
    else
        pred(predecessor) = find(curr);
        if pred->right is NULL
            pred->right = cur
            cur = cur->left
        else
            pred->right  = NULL
            visit(cur)
            cur = cur->right


In case of pre-order traversal -> we would visit cur after line-16 instead of line-20.
In case of post-order -> we would check for right-edge instead of left edge, pre would be from cur->right and reverse the vector at last.  
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root, *pre = NULL;
        while(cur!=NULL){
            if(cur->left == NULL){
                ans.emplace_back(cur->val);
                cur = cur->right;
            }else{
                //Find predecessor
                pre = cur->left;
                while(pre->right && pre->right != cur){
                    pre = pre->right;
                }

                //Create temp link
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                }else{
                    //Revert temp link
                    pre->right = NULL;
                    ans.emplace_back(cur->val);
                    cur = cur->right;
                }

            }
        }
        return ans;
    }
};