#include <iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Description: 
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
*/

struct ListNode{

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                q.push(lists[i]);
            }
        }
        ListNode* dum = new ListNode(0);
        ListNode*tmp = NULL;
        
        ListNode* cur = dum;
        while(!q.empty()){
            tmp = q.top();
            cout<<tmp->val<<" ";
            q.pop();
            cur->next = tmp;
            cur = tmp;
            if(tmp->next){
                q.push(tmp->next);
            }
        }
        return dum->next;
    }
};