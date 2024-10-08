#include<vector>
#include<iostream>

using namespace std;

/*
Description:
LeetCode wants to give one of its best employees the option to travel among n cities to collect algorithm problems. 
But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. 
Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions you need to follow.

Rules and restrictions:
-You can only travel among n cities, represented by indexes from 0 to n - 1. Initially, you are in the city indexed 0 on Monday.
-The cities are connected by flights. The flights are represented as an n x n matrix (not necessarily symmetrical), 
called flights representing the airline status from the city i to the city j. 
If there is no flight from the city i to the city j, flights[i][j] == 0; Otherwise, flights[i][j] == 1. Also, flights[i][i] == 0 for all i.
-You totally have k weeks (each week has seven days) to travel. 
You can only take flights at most once per day and can only take flights on each week's Monday morning.
Since flight time is so short, we do not consider the impact of flight time.
-For each city, you can only have restricted vacation days in different weeks, given an n x k matrix called days representing this relationship. 
For the value of days[i][j], it represents the maximum days you could take a vacation in the city i in the week j.
-You could stay in a city beyond the number of vacation days, but you should work on the extra days, which will not be counted as vacation days.
-If you fly from city A to city B and take the vacation on that day, the deduction towards vacation days will count towards the vacation days of city B in that week.
-We do not consider the impact of flight hours on the calculation of vacation days.
Given the two matrices flights and days, return the maximum vacation days you could take during k weeks.

Example:
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
Output: 21
Explanation:
One of the best strategies is:
1st week : stay at city 0, and play 7 days.
2nd week : fly from city 0 to city 1 on Monday, and play 7 days.
3rd week : fly from city 1 to city 2 on Monday, and play 7 days.
Ans = 7 + 7 + 7 = 21
*/

class Solution {
public:

    int n, k;

    int get(int city, int week, vector<vector<int>>& flights, vector<vector<int>>& days, vector<vector<int>> dp){
        if(week == k){
            return 0;
        }
        if(dp[city][week] != -1){
            return dp[city][week];
        }
        int ans = days[city][week] + get(city, week+1, flights, days, dp);
        for(int i=0; i<n; i++){
            if(flights[city][i] == 1){
                ans = max(ans, get(i, week+1, flights, days, dp) + days[i][week]);
            }
        }
        return dp[city][week] = ans;
    }

    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n = flights.size();
        k = days[0].size();
        vector<vector<int>> dp(n, vector<int>(k, -1));
        return get(0, 0, flights, days, dp);
    }

};

int main(){
    Solution s;
    vector<vector<int>> flights = {{0,1,1},{1,0,1},{1,1,0}};
    vector<vector<int>> days = {{7,0,0},{0,7,0},{0,0,7}};
    cout<<s.maxVacationDays(flights, days)<<endl;
}