#include<iostream>
using namespace std;

class heap{

public:

    int* arr;
    int size;
    int capacity;

    heap(int s){
        capacity = s;
        size = 0;
        arr = new int[s];
    }

    void print(){
        cout<<"Heap is: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int val){
        if(size==capacity){
            cout<<"Heap is full"<<endl;
            return;
        }
        int index = size;
        arr[size++] = val;
        int parent;
        while(index > 0){
            parent = (index-1)/2;
            if(arr[parent] < arr[index]){
                swap(arr[index], arr[parent]);
                index = parent;
            }else{
                break;
            }
        }
    }

    void remove(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return ;
        }
        arr[0] = arr[size-1];
        size--;
        int index = 0;
        heapify(index, size, arr);

    }

    void heapify(int index, int s, int a[]){
        int left, right, max;
        while(index < s){
            left = 2*index+1;
            right = 2*index+2;
            max = index;
            if(left<s && a[left] > a[max]){
                max = left;
            }
            if(right<s && a[right] > a[max]){
                max = right;
            }
            if(max != index){
                swap(a[index], a[max]);
                index = max;
            }else{
                break;
            }
        }
    }

    void heapSort(int s){
        swap(arr[0], arr[s-1]);
        heapify(0, s-1, arr);
    }

};

int main(){

    heap h(8);
    h.insert(10);
    h.insert(20);
    h.insert(23);
    h.insert(64);
    h.insert(12);
    h.insert(28);

    h.remove();


    h.print();

    //Heap-sort after heapify our array
    /*for(int i=0; i<h.size; i++){
        h.heapSort(h.size-i);
    }
    h.print();
    
    */




    /*int sz = 6;
    int nw[sz] = {10,20,23,64,12,28};
    for(int i = sz/2; i>=0; i--){
        h.heapify(i, sz, nw);
    }
    cout<<"After heapifying: ";
    for(int i=0; i<6; i++){
        cout<<nw[i]<<" ";
    }*/

    return 0;
}