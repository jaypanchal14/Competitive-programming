#include <iostream>
#include <unordered_map>
using namespace std;

/*
Description :
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy and return head of it.

Example :
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

// Definition for a Node.
class TreeNode {
public:
    int val;
    TreeNode* next;
    TreeNode* random;
    
    TreeNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    TreeNode* copyRandomList(TreeNode* head) {
        if (!head) return head;
        TreeNode* tmp = head;
        while(tmp){
            TreeNode* n = new TreeNode(tmp->val);
            n->next = tmp->next;
            tmp->next = n;
            tmp = n->next;
        }
        tmp = head;
        TreeNode* newHead = head->next;
        while(tmp){
            if(tmp->random){
                tmp->next->random = tmp->random->next;
            }
            tmp = tmp->next->next;
        }
        tmp = head;
        TreeNode* next = NULL;
        while(tmp){
            next = tmp->next->next;
            if(next)
                tmp->next->next = next->next;
            tmp->next = next;
            tmp = next;
        }
        return newHead;
    }

    TreeNode* copyRandomListWithMemory(TreeNode* head) {

        //To maintain map of old and new node mapping, which will be used for further pointer setting
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* tmp = head;
        while(tmp){
            m[tmp] = new TreeNode(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            m[tmp]->next = m[tmp->next];
            m[tmp]->random = m[tmp->random];
            tmp = tmp->next;
        }
        return m[head];
    }
};