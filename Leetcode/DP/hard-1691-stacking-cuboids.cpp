#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). 
Choose a subset of cuboids and place them on each other.

# Constraint -> You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 

You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
Return the maximum height of the stacked cuboids.
Example:
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other. 
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
*/


class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        int n = c.size();
        for(int i=0; i<n; i++){
            sort(c[i].begin(), c[i].end());
        }
        sort(c.begin(), c.end());
        vector<int> dp(n, 0);
        dp[n-1] = c[n-1][2];
        int ans = dp[n-1];
        int w, l, h;
        for(int i=n-2; i>=0; i--){
            w = c[i][0];
            l = c[i][1];
            h = c[i][2];
            dp[i] = h;
            for(int j=n-1; j>i; j--){
                if(w <= c[j][0] && l <= c[j][1] && h <= c[j][2]){
                    dp[i] = max(dp[i], h+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};