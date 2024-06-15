#include<iostream>

using namespace std;

/*
Description :
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.

Example :
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]
*/

class MyCircularDeque {

    int size;
    int q_front, q_rear;
    int* arr;

public:
    MyCircularDeque(int k) {
        size = k;
        q_front = q_rear = -1;
        arr = new int[size];
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(q_front==-1){
            q_front = 0;
            q_rear = 0;
        }else if (q_front==0){
            q_front = size-1;
        }else{
            q_front--;
        }
        arr[q_front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(q_front==-1){
            q_front = 0;
            q_rear = 0;
        }else if (q_rear==size-1){
            q_rear = 0;
        }else{
            q_rear++;
        }
        arr[q_rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        if(q_front == q_rear){
            q_front = -1;
            q_rear = -1;
        }else if (q_front==size-1){
            q_front = 0;
        }else{
            q_front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        if(q_front == q_rear){
            q_front = -1;
            q_rear = -1;
        }else if (q_rear==0){
            q_rear = size-1;
        }else{
            q_rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return arr[q_front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[q_rear];
    }
    
    bool isEmpty() {
        return q_front == -1;
    }
    
    bool isFull() {
        if((q_front==0 && q_rear==size-1) || (q_rear+1 == q_front)){
            return true;
        }
        return false;
    }
};