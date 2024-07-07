#include<iostream>

using namespace std;

/*
Linked list : Linear data structure, pointing to next node of the list or NULL.
Each node atleast contains : a value and address of next node(pointer).
*/

class TreeNode{
    public:
    int val;
    TreeNode* next;

    TreeNode(){
        this->val = 0;
        this->next = NULL;
    }

    TreeNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(TreeNode* &node, int n){
    TreeNode* tmp = new TreeNode(n);
    tmp->next = node;
    node = tmp;
}

void insertAtEnd(TreeNode* &node, int n) {
    if (node == NULL) {
        insertAtHead(node, n);
        return;
    }
    
    TreeNode* tmp = new TreeNode(n);
    TreeNode* curr = node;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = tmp;
}

void insertAtPosition(TreeNode* &node, int val, int position){
    if(position==1){
        insertAtHead(node, val);
        return ;
    }

    TreeNode *prev=NULL, *curr=node;
    int i=1;
    while(curr!=NULL && i<position){
        prev=curr;
        curr=curr->next;
        i++;
    }
    if(curr==NULL && i==position){
        cout<<"We are inserting at the end\n";
        insertAtEnd(node, val);
        return ;
    }

    if(!curr){
        cout<<"Wrong position requested, linked-list is not of the expected size.\n";
        return;
    }
    prev->next=new TreeNode(val);
    prev->next->next=curr;
}

//Check the function
void deleteNode(TreeNode* head, int val){
    // If the list is empty or contains only one element
    if (head == NULL || head->next == NULL) {
        delete head;
        return;
    }
 
    /* Delete the head */
    if (head != NULL && head->val==val) {
        TreeNode* temp = head->next;
    } else {
        TreeNode* prev = head;
        TreeNode* current = head->next;
        while (current != NULL) {
            if (current->val==val) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}

//Reverse the linkedlist
void reverseLinkedList(TreeNode* node){
    TreeNode *prev = NULL;
    TreeNode *curr = node;
    TreeNode *next = curr->next;
    
    curr->next = prev;
    
    while (next != NULL) {
        prev = curr;
        curr = next;
        next = next->next;
        
        curr->next = prev;
    }
   node=curr;
}

void printLinkedList(TreeNode* node) { 
    TreeNode* temp = node;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}    

int main(){
    TreeNode* n1 = new TreeNode(10);
    TreeNode* n2 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(7);

    n2->next = n3;
    n1->next = n2;

    cout << "Given Linked list is : \n";
    
    insertAtHead(n1, 8);
    insertAtHead(n1, 6);
    insertAtHead(n1, 4);
    //printLinkedList(n1);
    
    // Insertion at a specific position in the linked list.
    insertAtPosition(n1, 9, 7);
    printLinkedList(n1);

    return 0;
}