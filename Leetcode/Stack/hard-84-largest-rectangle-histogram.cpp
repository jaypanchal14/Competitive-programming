#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/*
Description :
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
Example:
Input: heights = [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:

    vector<int> getPrevious(vector<int>& h){
        vector<int> v(h.size());
        stack<int> s;
        s.push(-1);
        for(int i=0; i<h.size(); i++){
            while(s.top()!=-1 && h[s.top()]>=h[i]){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> getNext(vector<int>& h){
        vector<int> v(h.size());
        stack<int> s;
        s.push(-1);
        for(int i=h.size()-1; i>=0; i--){
            while(s.top()!=-1 && h[s.top()]>=h[i]){
                s.pop();
            }
            if(s.top()==-1){
                v[i] = h.size();
            }else{
                v[i] = s.top();
            }
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& h) {
        vector<int> v(h.size());
        vector<int> next = getNext(h);
        int ans = 0, tmp;
        stack<int> s;
        s.push(-1);
        for(int i=0; i<h.size(); i++){

            while(s.top()!=-1 && h[s.top()]>=h[i]){
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        
            tmp = h[i]*(next[i]-v[i]-1);
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v = {2,1,5,6,2,3};
    cout<<"Largest area:"<<s.largestRectangleArea(v)<<endl;
    return 0;
}