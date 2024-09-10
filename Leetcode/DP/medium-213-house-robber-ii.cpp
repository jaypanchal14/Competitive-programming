#include<vector>

using namespace std;

/*
Description:
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            if(nums[1]>=nums[0]){
                return nums[1];
            }
            return nums[0];
        }
        int take, nonTake;
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        //First consider 0 to n-2 houses
        for(int i=2; i<n-1; i++){
            take = nums[i]+prev2;
            prev2 = prev1;
            prev1 = max(take, prev1);
        }
        int ans = prev1;

        //Consider 1 to n-1 houses
        prev2 = nums[1];
        prev1 = max(nums[1], n>2 ? nums[2] : 0);
        for(int i=3; i<n; i++){
            take = nums[i]+prev2;
            prev2 = prev1;
            prev1 = max(take, prev1);
        }
        return max(ans, prev1);
    }
};