#include<iostream>
using namespace std;

/*
Description :
Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example :
Input: head = [1,1,1,2,3]
Output: [2,3]
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *prev = dummy, *cur = head;
        while(cur){
            //if duplicate
            if(cur && cur->next && cur->val==cur->next->val){
                while(cur && cur->next && cur->val==cur->next->val){
                    cur = cur->next;
                }
                cur = cur->next;
                prev->next = cur;
            }else{
            //otherwise
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};