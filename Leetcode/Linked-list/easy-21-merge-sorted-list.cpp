#include<iostream>
using namespace std;

/*
Description :
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example :
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
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

    //Using merge logic
    ListNode* mergeTwoListsMerge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0, NULL);
        ListNode* tmp = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;
            }else{
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            }
        }
        if(list1){
            tmp->next = list1;
        }
        if(list2){
            tmp->next = list2;
        }
        return dummy->next;
    }

    //using insertion logic
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val > list2->val){
            return mergeTwoLists(list2, list1);
        }
        ListNode* cur = list1, *next = list1->next;
        while(next && list2){
            if(cur->val<=list2->val && next->val>=list2->val){
                cur->next = list2;
                list2 = list2->next;
                cur->next->next = next;
                cur = cur->next;
            }else{
                cur = next;
                next = next->next;
            }
        }
        if(list2){
            cur->next = list2;
        }
        return list1;
    }
};