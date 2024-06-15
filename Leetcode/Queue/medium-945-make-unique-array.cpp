#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
Description:
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
Return the minimum number of moves to make every value in nums unique.
Example :
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& n) {
        sort(n.begin(), n.end());
        int ans = 0;
        int prev = n[0];
        /*
        Logic is to first sort it, and keep comparing the current with previous element, checking how much difference 
        is there in between those two.
        */
        for(int i=1; i<n.size(); i++){
            if(n[i]<=prev){
                ans += prev+1-n[i];
                prev++;
            }else{
                prev = n[i];
            }
        }
        return ans;
    }

    //Gives TLE if we just simulate the situation as mentioned in the problem
    int minIncrementForUniqueTLE(vector<int>& n) {
        int ans = 0;
        priority_queue<int , vector<int>, greater<int>> q;
        for(int i=0;i<n.size(); i++){
            q.push(n[i]);
        }
        int prev = -1, cur;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(cur==prev){
                ans++;
                q.push(cur+1);
            }else{
                prev = cur;
            }
        }
        return ans;
    }

};