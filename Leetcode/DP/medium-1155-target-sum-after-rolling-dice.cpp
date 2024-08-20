#include<vector>

using namespace std;

/*
Description:
You have n dice, and each dice has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, 
so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Example:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
*/

class Solution {
public:

    int MOD = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {
//        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
//        return get(n, k, target, dp);
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                ans = 0;
                for(int x=1; x<=k; x++){
                    if(j-x>=0){
                        ans = (ans + dp[i-1][j-x])%MOD;
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][target];
    }

    int get(int n, int k, int target, vector<vector<int>>& dp){
        if(n==0){
            return target==0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i=1; i<=k; i++){
            if(target-i>=0){
                ans = (ans+get(n-1, k, target-i, dp))%MOD;
            }
        }
        return dp[n][target] = ans; 
    }
};