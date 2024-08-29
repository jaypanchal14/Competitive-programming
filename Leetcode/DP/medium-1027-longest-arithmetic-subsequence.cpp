#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
Note that:
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
0 <= nums[i] <= 500
Example:
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].
*/

class Solution {
public:

    int n;

    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        int ans = 0, diff;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for(int r=0; r<n; r++){
            for(int l=0; l<r; l++){
                diff = nums[l]-nums[r]+500;
                dp[r][diff] = dp[l][diff]+1;
                ans = max(ans, dp[r][diff]);
            }
        }
        return ans+1;

        //Memoization giving TLE
/*        int ans = 2;
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, 2+unget(j, nums[j]-nums[i]+500, nums, dp));
            }
        }
*/
        //Below logic will work iff we can change the order of input
        /*
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(n, vector<int>(nums[n-1]-nums[0]+1, -1));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, 2+get(j, nums[j]-nums[i], nums, dp));
            }
        }
        return ans;*/
    }

    int unget(int cur, int diff, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[cur][diff]!=-1){
            return dp[cur][diff];
        }
        int ans = 0, tmp;
        for(int i=cur+1; i<n; i++){
            tmp = nums[i]-nums[cur]+500;
            if(diff==tmp){
                ans = max(ans, 1+unget(i, diff, nums, dp));
            }
        }
        return dp[cur][diff] = ans;
    }

    //This will work for sorted order nums only
    int get(int cur, int diff, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[cur][diff]!=-1){
            return dp[cur][diff];
        }
        int ans = 0, tmp;
        for(int i=cur+1; i<n; i++){
            tmp = nums[i]-nums[cur];
            if(diff>tmp){
                continue;
            
            }else if(diff==tmp){
                ans = max(ans, 1+get(i, diff, nums, dp));
            
            }else{
                break;
            }
        }
        return dp[cur][diff] = ans;
    }
};