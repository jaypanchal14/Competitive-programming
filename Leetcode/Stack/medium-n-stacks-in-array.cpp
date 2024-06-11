#include<iostream>

using namespace std;

/*
Description :
Implement N stacks with a single array in a space optimized approach.
*/

class Nstack{

    //To store values
    int* arr;
    //To store top of respective stacks
    int* top;
    //To store either previous element of stack or next freespot
    int* next;

    //Number of stacks
    int n;
    //Size of array
    int s;
    int freespot;

    public :

    Nstack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        for(int i=0; i<s-1; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        top = new int[n];
        for(int i=0; i<n; i++){
            top[n] = -1;
        }

        freespot = 0;
    }

    bool push(int s, int val){
        if(freespot == -1){
            //Array is full/overflow
            return false;
        }

        int index = freespot;
        arr[index] = val;
        freespot = next[index];
        next[index] = top[s-1];
        top[s-1] = index;
        return true;
    }

    int pop(int s){
        if(top[s-1]==-1){
            return -1;
        }
        int index = top[s-1];
        top[s-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};