#include<iostream>
using namespace std;

/*
Description :
Sort the linkedlist using merge-sort technique.
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
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sort(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sort(left);
        right = sort(right);
        return merge(left, right);
    }

    ListNode* merge(ListNode* l, ListNode* r){
        if(!r){
            return l;
        }
        if(!l){
            return r;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while(l && r){
            if(l->val <= r->val){
                tmp->next = l;
                l = l->next;
                tmp = tmp->next;
            }else{
                tmp->next = r;
                r = r->next;
                tmp = tmp->next;
            }
        }
        if(l){
            tmp->next = l;
        }
        if(r){
            tmp->next = r;
        }
        return dummy->next;
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

    ListNode *head = new ListNode(10, new ListNode(2, new ListNode(5, NULL)));
    ListNode *h = new ListNode(8, new ListNode(23, new ListNode(912, head)));
    Solution obj;
    cout<<"Before: ";
    obj.print(h);
    ListNode* newHead = obj.sort(h);
    cout<<"After:  ";
    obj.print(newHead);
    return 0;
}