#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
Example:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to 
(-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
           
        int ans = 0, n = s.size(), prefix = 0;
        // Top to bottom dp
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return get(0, 0, s, dp);
        for(int i=n-1; i>=0; i--){
            if(prefix+s[i]<0){
                break;
            }
            prefix += s[i];
            ans += prefix;
        }
        return ans;
    }

    int get(int i, int time, vector<int>& s, vector<vector<int>>& dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i][time]!=-1){
            return dp[i][time];
        }
        int exc = get(i+1, time, s, dp);
        int inc = s[i]*(time+1) + get(i+1, time+1, s, dp);
        return dp[i][time] = max(exc, inc);
    }
};