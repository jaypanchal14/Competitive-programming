#include<iostream>
using namespace std;

/*
Description :
Given the head of a linked list, return the list after sorting it in ascending order.
Example :
Input: head = [4,2,1,3]
Output: [1,2,3,4]
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

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* first, ListNode* second){
        if(!first){
            return second;
        }
        if(!second){
            return first;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while(first && second){
            if(first->val <= second->val){
                tmp->next = first;
                first = first->next;
                tmp = tmp->next;
            }else{
                tmp->next = second;
                second = second->next;
                tmp = tmp->next;
            }
        }
        if(first){
            tmp->next = first;
        }
        if(second){
            tmp->next = second;
        }
        return dummy->next;
    }

    //Using merging logic of divide and combine
    // Divide the linked-list in half, sort respective list and combine thereafter
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};