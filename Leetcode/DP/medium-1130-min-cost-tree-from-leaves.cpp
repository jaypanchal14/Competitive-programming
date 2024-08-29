#include<vector>

using namespace std;

/*
Description:
Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer.

Example:
Input : arr = [6,2,4,11]
Output : 98

Approach:
1) Store the maxi element between all the possible ranges, i.e., maxi 2D vector.
2) Check for all the possible trees, finding the parent node value from the divided two, left and right sub-trees maxi element.
3) Keep the maxi and sub-trees sum values in check

*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), tmp;
        vector<vector<int>> maxi(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            tmp = arr[i];
            for(int j=i; j<n; j++){
                if(tmp < arr[j]){
                    tmp = arr[j];
                }
                maxi[i][j] = tmp;
            }
        }

        //Memoization
        //vector<vector<int>> dp(n, vector<int>(n, -1));
        //return get(0, n-1, dp, maxi);

        //Tabulation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j){
                    dp[i][j] = 0;
                }else{
                    tmp = 1e9;
                    for(int k=i; k<j; k++){
                        tmp = min(tmp, maxi[i][k]*maxi[k+1][j] + dp[i][k] + dp[k+1][j]);
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[0][n-1];
    }

    int get(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& maxi){
        if(i>=j){
            // return maxi[i][j];
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 1e9;
        // int ans = maxi[i][i]*maxi[i+1][j] + get(i+1, j, dp, maxi);
        for(int k=i; k<j; k++){
            ans = min(ans, maxi[i][k]*maxi[k+1][j] + get(i, k, dp, maxi)
                        + get(k+1, j, dp, maxi));
        }
        return dp[i][j] = ans;
    }
};