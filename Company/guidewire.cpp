#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Que : 1
An array consists of integer numbers having total sum as non-negative, Positive and negative value indicates credit and debit transactions.
At any instance of time, the prefix sum of the array elements should never be negative. 
If it happens, you can pick the negative element and append it at the end.
Return the minimum number of such operations so that all the prefix sum are non-negative.

Que : 2
Variation of leetcode - 2391
Instead of returning the total time, we were asked to return the maximum time amongst the three trucks
*/

int getCount(vector<int>& nums){
    int ans = 0, pre = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int& num : nums){
        pre += num;
        if(num <= 0){
            q.push(num);
        }
        while(pre<0 && !q.empty()){
            pre -= q.top();
            q.pop();
            ans++;
        }
    }
    return ans;
}

int main(){

    vector<int> v = {10, -10, -1, -1, 2};
    cout << getCount(v) << endl;
    return 0;
}