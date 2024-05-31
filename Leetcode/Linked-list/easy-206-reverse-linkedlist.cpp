#include <iostream>
using namespace std;

/*
Description : 
Reverse the nodes of linkedlist without modifying the nodes' values.

*/

struct ListNode{

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
    //Iterative
    ListNode *reverseListIterative(ListNode *head){
        if (!head || !head->next){
            return head;
        }
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    //Recursive
    ListNode *reverseListRecursive(ListNode *head){
        if (!head || !head->next){
            return head;
        }
        ListNode* nh = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
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

    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, NULL)));
    Solution obj;
    cout<<"Before: ";
    obj.print(head);
    // ListNode* newHead = obj.reverseListIterative(head);
    ListNode* newHead = obj.reverseListRecursive(head);
    cout<<"After:  ";
    obj.print(newHead);
    return 0;
}