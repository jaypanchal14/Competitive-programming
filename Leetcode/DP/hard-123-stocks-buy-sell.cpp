#include<vector>

using namespace std;

/*
Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.

Example:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

class Solution {
public:

    int n;

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        
        //If you want the number of transactions to not exceed 'x', replace limit 3 with 'x+1'
        //Similar to leetcode-188 (where they have given k limit)
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=2; k>0; k--){
                    //j == 1 -> canBuy
                    if(j){
                        int buy = dp[i+1][0][k] - prices[i];
                        int skip = dp[i+1][1][k];
                        dp[i][j][k] = max(buy, skip);
                    }else{
                        int sell = dp[i+1][1][k-1] + prices[i];
                        int skip = dp[i+1][0][k];
                        dp[i][j][k] = max(sell, skip);
                    }
                }
            }
        }
        return dp[0][1][2];
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        // return get(0, 1, 0, prices, dp);
    }

    int get(int index, int canBuy, int c, vector<int>& p, vector<vector<vector<int>>>& dp){
        if(index==n || c==2){
            return 0;
        }
        if(dp[index][canBuy][c]!=-1){
            return dp[index][canBuy][c];
        }
        int ans = 0;
        //No stock is in hold
        if(canBuy){
            int buy = get(index+1, 0, c, p, dp) - p[index];
            int skip = get(index+1, 1, c, p, dp);
            ans = max(buy, skip);
        }else{
            //Need to either sell here or skip
            int sell = get(index+1, 1, c+1, p, dp) + p[index];
            int skip = get(index+1, 0, c, p, dp);
            ans = max(sell, skip);
        }

        return dp[index][canBuy][c] = ans;
    }
};