#include<iostream>
using namespace std;

/*
Description :
Given head, the head of a linked list, determine if the linked list has a cycle in it.
Return true if there is a cycle in the linked list. Otherwise, return false.

- In floyd warshal algo for detecting the cycle and find the loop node,
  Let's suppose, the nodes are as below and slow and fast pointer will meet at third node of the loop.

n -> n -> n -> n -> n -> n  <--- this is the third node
               ^         |
               |         >
               n   <--   n

A = Distance between head and first node of cycle
B = Distance between first node of cycle to meet-pointer
C = Cycle Distance
Distance covered by slow : A + y*C + B
Distance covered by fast : A + x*C + B
Equation : fast = 2*slow
=>  A + x*C + B = 2(A + y*C + B)
    C * (x-2y) = A + B      here, x-2y will be constant for any linkedlist having cycle
=>  C * K = A + B
This means, the node at which both will will be "A" from head and "A" from meet-point in the cycle.

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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode *fast = head, *slow= head;
        while(fast && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
            
        }
        return false;
    }
};