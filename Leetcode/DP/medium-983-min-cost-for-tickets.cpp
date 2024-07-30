#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Description:
You have planned some train traveling one year in advance. 
The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
Train tickets are sold in three different ways:
a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.
Return the minimum number of dollars you need to travel every day in the given list of days.
Example:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
*/

class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int ans = 0;
        queue<pair<int,int>> w,m;
        for(int& d : days){
            while(w.size()>0 && w.front().first+7 <= d){
                w.pop();
            }
            while(m.size()>0 && m.front().first+30 <= d){
                m.pop();
            }

            m.push({d, ans+costs[2]});
            w.push({d, ans+costs[1]});

            ans = min(ans+costs[0], min(w.front().second, m.front().second));
        }
        return ans;
        
        //Top-bottom
        // vector<int> dp(days.size()+1, -1);
        // dp[days.size()] = 0;
        // get(0, days, costs, dp);
        /*
        //Bottom-up
        int n = days.size(), b , c, index;
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            dp[i] = costs[0]+dp[i+1];
            index = i;
            while(index<days.size() && days[index]<days[i]+7){
                index++;
            }
            if(dp[i] > costs[1] + dp[index]){
                dp[i] = costs[1] + dp[index];
            }
            index = i;
            while(index<days.size() && days[index]<days[i]+30){
                index++;
            }
            if(dp[i] > costs[2] + dp[index]){
                dp[i] = costs[2] + dp[index];
            }
        }
        return dp[0];
        */
    }

    int get(int index, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //Check for 1 day
        dp[index] = costs[0] + get(index+1, days, costs, dp);
        //Check for 7 day
        int i = index;
        while(i<days.size() && days[i]<days[index]+7){
            i++;
        }
        dp[index] = min(dp[index], costs[1] + get(i, days, costs, dp));
        //Check for 30 days
        i = index;
        while(i<days.size() && days[i]<days[index]+30){
            i++;
        }
        dp[index] = min(dp[index], costs[2] + get(i, days, costs, dp));
        return dp[index];
    }
};