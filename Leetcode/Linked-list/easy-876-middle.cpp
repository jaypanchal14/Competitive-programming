#include<iostream>
using namespace std;

/*
Description :
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Ex : 
Input: head = [1,2,3,4,5]
Output: [3,4,5]
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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    ListNode *sec = new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, NULL))));
    ListNode *head = new ListNode(1, new ListNode(2, sec));
    Solution sol;
    ListNode *res = sol.middleNode(head);
    while(res){
        cout<<res->val<<" -> ";
        res = res->next;
    }
    cout<<endl;

    return 0;
}