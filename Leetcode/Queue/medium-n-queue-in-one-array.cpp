#include<iostream>

using namespace std;

class NQueue{

    int n, k, freespot;
    int* arr;
    int* front;
    int* rear;
    int* next;

public:
    //N : total size, K : k-queue
    NQueue(int N, int K){
        n = N;
        k = K;
        freespot = 0;

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }

    bool push(int q, int val){
        if(freespot == -1){
            cout<<"Overflow.\n";
            return false;
        }
        int index = freespot;

        //update freespot
        freespot = next[index];
        //update main array
        arr[index] = val;
        //if q is empty (update front)
        if(front[q-1]==-1){
            front[q-1] = index;
        }else{
            //To link previous rear to new rear
            next[rear[q-1]] = index;
        }

        //update rear
        rear[q-1] = index;

        //update next
        next[index] = -1;
        return true;
    }

    int pop(int q){
        if(front[q-1]==-1){
            cout<<"Underflow.\n";
            return -1;
        }

        //Get index from front
        int index = front[q-1];
        //Update front
        front[q-1] = next[index];
        //Update next
        next[index] = freespot;
        //Update freespot
        freespot = index;
        return arr[index];
    }


};