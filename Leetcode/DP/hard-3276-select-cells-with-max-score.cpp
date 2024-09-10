#include<vector>
#include<iostream>

using namespace std;

/*
Description:
You are given a 2D matrix grid consisting of positive integers.
You have to select one or more cells from the matrix such that the following conditions are satisfied:
->No two selected cells are in the same row of the matrix.
->The values in the set of selected cells are unique.
Your score will be the sum of the values of the selected cells. Return the maximum score you can achieve.

Example:
Input: grid = [[8,7,6],[8,3,2]]
Output: 15

Logic:
1) First get the rows number for each value and store it in the mapping vector.
2) Start searching from highest possible number( here, it is 100) and keep updating the bitmask 
whenever you select a value and its respective row.

Range of mask if from [0,1023] (2^10 different possibilities)
*/


class Solution {
public:

    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mp(101);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]].emplace_back(i);
            }
        }
        vector<vector<int>> dp(101, vector<int>(1025, -1));
        return get(100, 0, dp, mp);
    }

    int get(int num, int mask, vector<vector<int>>& dp, vector<vector<int>>& mp){
        if(num==0){
            return 0;
        }
        if(dp[num][mask]!=-1){
            return dp[num][mask];
        }
        int ans = get(num-1, mask, dp, mp);
        for(int& x : mp[num]){
            //Check if particular row 'x' is already used or not
            if((mask & (1<<x))==0){
                ans = max(ans, num+get(num-1, mask | (1<<x), dp, mp));
            }
        }
        return dp[num][mask] = ans;
    }
};