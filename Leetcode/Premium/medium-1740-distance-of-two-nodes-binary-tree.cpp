#include<iostream>
#include<queue>
using namespace std;

/*
Description:
Given the root of a binary tree and two integers p and q, return the distance between the nodes of value p and value q in the tree.
The distance between two nodes is the number of edges on the path from one to the other.
Example:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
Output: 3
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

     bool getPath(TreeNode* root, int& val, vector<int>& v){
          if(!root){
               return false;
          }
          v.push_back(root->val);
          if(root->val == val){
               return true;
          }
          if(root->left){
               if(getPath(root->left, val, v)){
                    return true;
               }
               else{
                    v.pop_back();
               }
          }
          if(root->right){
               if(getPath(root->right, val, v)){
                    return true;
               }else{
                    v.pop_back();
               }
          }
          return false;
     }

     int findDistance(TreeNode* root, int p, int q) {
          int ans = 0;
          vector<int> vp, vq;
          getPath(root, p, vp);
          getPath(root, q, vq);
          int i = 0;
          while(i < vp.size() && i < vq.size() && vp[i]==vq[i]){
               i++;
          }
          return vp.size()-2*i+ vq.size();
     }

};

int main(){

     Solution s;
     TreeNode* root = new TreeNode(3);
     root->left = new TreeNode(5);
     root->right = new TreeNode(1);
     root->left->left = new TreeNode(6);
     root->left->right = new TreeNode(2);
     root->right->left = new TreeNode(0);
     root->right->right = new TreeNode(8);
     root->left->right->left = new TreeNode(7);
     root->left->right->right = new TreeNode(4);
     cout<<"Distance between 6 and 0 is: "<<s.findDistance(root, 6, 4);
     return 0;
}