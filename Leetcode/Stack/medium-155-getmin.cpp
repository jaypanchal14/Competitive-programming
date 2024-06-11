#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
Description :
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
*/

class MinStackWithSpace {
public:

    vector<int> v;
    vector<int> mini;

    MinStackWithSpace() {

    }
    
    void push(int val) {
        if(v.size()==0){
            v.push_back(val);
            mini.push_back(val);
        }else{
            v.push_back(val);
            mini.push_back(min(val, mini.back()));
        }
    }
    
    void pop() {
        v.pop_back();
        mini.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

//Without extra space
class MinStack {

public :
    stack<int> s;
    int mini;

    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini = val;
        }else{
            if(val<mini){
                s.push(2*val - mini);
                mini = val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.size()==0){
            return ;
        }
        int tmp = s.top();
        if(tmp>mini){
            return ;
        }else{
            int prevMin = mini;
            int val = 2*mini - tmp;
            mini = val;
            return ;
        }

    }

    bool isEmpty() {
        return s.empty();
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }
        int val = s.top();
        if(val > mini){
            return val;
        }else{
            return mini;
        }
    }
    
    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }
    

};