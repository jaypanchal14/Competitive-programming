#include <iostream>
#include <queue>
using namespace std;

/*
Description:
Given a root of a binary-tree, check if it follows below  property in level order traversal.
1) All nodes at even depth should have odd value and are in strictly incresing order.
2) All nodes at odd depth should have even value and are in strictly decreasing order.

Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
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
    bool isEvenOddTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val & 1;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool isEvenLevel = true;
        int val, newVal, size;
        TreeNode* tmp = NULL;
        while (!q.empty()) {
            size = q.size();
            for (int i = 0; i < size; i++) {
                tmp = q.front();
                q.pop();
                //To check for first element of the level
                if (i == 0) {
                    val = tmp->val;
                    if (isEvenLevel && (val & 1) == 0) {
                        return false;
                    }
                    if (!isEvenLevel && (val & 1) == 1) {
                        return false;
                    }
                }
                else{
                    newVal = tmp->val;
                    if (isEvenLevel) {
                        if (newVal <= val || (newVal&1) == 0) {
                            return false;
                        }
                    } else {
                        if (newVal >= val || (newVal&1) == 1) {
                            return false;
                        }
                    }
                    val = newVal;
                }
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            isEvenLevel = !isEvenLevel;
        }

        return true;
    }
};