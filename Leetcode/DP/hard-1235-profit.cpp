#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Description :
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/

int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {   
    int n = s.size(); 
    vector<pair<int, int>> st(n);
    for(int i = 0; i < n; i++) st[i] = {s[i], i};
    sort(st.begin(), st.end());
    vector<int> dp(n+1, 0); 
    for(int i = n-1; i > -1; i--)
        dp[i] += max(dp[i+1], p[st[i].second] + dp[lower_bound(st.begin() + i, st.end(), make_pair(e[st[i].second], 0)) - st.begin()]);
    return dp[0];
}

//Gives TLE
int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    int s = start.size();
    vector<int> dp(s+1, 0);
    vector<pair<int, int>> pairs;
    for (int i = 0; i < s; i++){
        pairs.push_back({start[i], i});
    }
    sort(pairs.begin(), pairs.end());
    for (int i = s - 1; i > -1; i--){
        int et = end[pairs[i].second];
        int pr = profit[pairs[i].second];
        int tmp = pr;
        //For selecting current job
        for (int j = i + 1; j < s; j++){
            if(start[pairs[j].second]>=et){
                tmp = max(tmp, pr + dp[j]);
                break;
            }
        }
        //Max between with selecting and not-selecting current job
        dp[i] = max(dp[i+1], tmp);
    }
    return dp[0];
}

