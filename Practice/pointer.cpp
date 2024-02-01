#include<iostream>

using namespace std;

//Below function is equivalent to : int getSum(int *arr, int size)
int getSum(int arr[], int size){

    int ans = 0;
    for(int i=0; i<size; i++){
        ans += i[arr];
    }
    return ans;
}

int main(){

    /*
    Pointer : A variable which stores the address of another variable(It can be of any data-type).
    As, it just stores the address of variable, it would always be 8 bytes in normal computer.

    There are two ways of initializing the pointer.
    */

    int a = 10;

    //Null pointer initialization -> int *p1 = 0;
    
    //First way
    int *p1 = &a; 
    //cout<<"Size of pointer:"<<sizeof(p1)<<endl;
    
    //Second way
    int *p2;
    p2 = &a;

    //This will print : 11 and 11 respectively from a and p1
    //cout<<"Before with variable a:"<<a<<", or from pointer p1:"<<(*p1)++<<endl;
    //This will print 11 and 11 respectively from a and p1
    //cout<<"Before with variable a:"<<a++<<", or from pointer p1:"<<(*p1)<<endl;
    //This will print 12 and 12 respectively from a and p2
    //cout<<"After with variable a:"<<a<<", or from pointer p2:"<<*p2<<endl;
    
    //int x[3] = {2}; // it is equivalent to x = {2,0,0}
    int b[4] = {1,2,3,4};
    cout<<"sum of b from 0th index:"<<getSum(b,4)<<endl;
    cout<<"sum of b from 4th index:"<<getSum(b+3,1)<<endl;
    
    //cout<<"Address of b or its first element:"<<&b<<endl;
    //cout<<"Second element :"<<*(b+1)<<endl; //2
    //cout<<"First element :"<<0[b]<<endl; //1
    //cout<<sizeof(*b)<<" or "<<sizeof(b)<<endl; // 4 or 16

    //Character array (last character is '\n' by implicit, and if we explicitly change it, it will give error)
    char cc[6] = "ashfh";
    cout<<cc;

    //Difference betweene printing int array and char array is this :
    //In int array, it will only print int stored at current address, whereas for char array, it will keep printing till we reach '\n'.

    return 0;
}

