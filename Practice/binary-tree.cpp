#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val = -1;
        left = right = NULL;
    }

    TreeNode(int v){
        val = v;
        left = right = NULL;
    }
};

void reverseLevelTraversal(TreeNode* root){
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    q.push(NULL);
    TreeNode* tmp = NULL;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        s.push(tmp);
        if(tmp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            
        }
    }
    tmp = s.top();
    if(tmp==NULL){
        s.pop();
    }
    while(!s.empty()){
        tmp = s.top();
        s.pop();
        if(tmp==NULL){
            cout<<endl;
        }else{
            cout<<tmp->val<<" ";
        }
    }
}

void levelOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    TreeNode* tmp = NULL;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp == NULL){
            //Level completed
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
            }
        }else{
            cout << tmp->val << " ";
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
        
    }
    /*while(!q.empty()){
        tmp = q.front();
        cout << tmp->val << " ";
        q.pop();
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }*/
    /*while(!q.empty()){
        for(int s = q.size(); s>=0; s--){
            tmp = q.front();
            q.pop();
            cout << tmp->val << " ";
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
    }*/
    cout<<endl;

}

TreeNode* buildTree(){
    TreeNode* root = new TreeNode();
    root->val = 1;
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    return root;
}

void getLevelWithVector(TreeNode* root){
    if(root==NULL){
        return;
    }
    vector<vector<TreeNode*>> v;
    v.push_back({root});
    int level = 0;
    vector<TreeNode*> cur = v[0];
    while(cur.size()>0){
        level++;
        v.push_back({});
        for(int i=0;i<cur.size(); i++){
            if(cur[i]->left){
                v[level].push_back(cur[i]->left);
            }
            if(cur[i]->right){
                v[level].push_back(cur[i]->right);
            }
        }
        cur = v[level];
    }
    v.pop_back();
    cout<<"Level-order traversal: \n";
    for(int i=0; i<level; i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]->val<<" ";
        }
        cout<<endl;
    }
    /*cout<<"Reverse Level-order traversal: \n";
    for(int i=level-1; i>=0; i--){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]->val<<" ";
        }
        cout<<endl;
    }*/

}

int main(){
    TreeNode* root = buildTree();
    cout<<"Level-order traversal: \n";
    //getLevelWithVector(root);
    /*levelOrderTraversal(root);
    cout<<"Reverse level-order traversal: \n";
    reverseLevelTraversal(root);*/

    return 0;
}