#include <iostream>
using namespace std;

/*
Description:
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example :
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* tmp = head;
        while(count<k && tmp){
            tmp = tmp->next;
            count++;
        }
        if(count<k){
            return head;
        }
        ListNode* nextHead = reverseKGroup(tmp, k);
        tmp = head;
        ListNode *prev = NULL, *next = NULL;
        while(count){
            next = tmp->next;
            if(count==k){
                tmp->next = nextHead;
            }else{
                tmp->next = prev;
            }
            prev = tmp;
            tmp = next;
            count--;
        }
        return prev;
    }

    void print(ListNode *head){
        ListNode *tmp = head;
        while(tmp){
            cout<<tmp->val<<" -> ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};

int main(){

    ListNode *head2 = new ListNode(4, new ListNode(5, new ListNode(6, NULL)));
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, head2)));
    Solution obj;
    cout<<"Before: ";
    obj.print(head);
    ListNode* newHead = obj.reverseKGroup(head, 4);
    cout<<"After:  ";
    obj.print(newHead);
    return 0;
}