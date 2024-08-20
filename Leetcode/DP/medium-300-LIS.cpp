#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), index, x;
        
        //Optimal T.C : O(n*logn)
        vector<int> tmp;
        tmp.emplace_back(nums[0]);
        for(int i=1; i<n; i++){
            x = nums[i];
            if(x>tmp.back()){
                tmp.emplace_back(x);
            }else{
                index = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
                tmp[index] = x;
            }
        }
        return tmp.size();

        /* 
        //T.C : O(n^2), S.C : O(N)
        vector<int> v(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    v[i] = max(v[i],1+v[j]);
                }
            }
        }
        return *max_element(v.begin(), v.end());
        */
        //vector<vector<int>> dp(n, vector<int>(n+1,-1));
        //return get(0, -1, nums, dp);
    }

    int get(int index, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int a = 0;
        if(prev==-1 || nums[index]>nums[prev]){
            a = 1+get(index+1, index, nums, dp);
        }
        a = max(a, get(index+1, prev, nums, dp));
        return dp[index][prev+1] = a;
    }

};