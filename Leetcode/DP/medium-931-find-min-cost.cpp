#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
Description :
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the 
element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

class Solution {
public:

    int row, col;
    vector<vector<int>> dp;

    int minFallingPathSum(vector<vector<int>>& m) {
        row = m.size();
        col = m[0].size();
        for(int i=1;i<row; i++){
            for(int j=0; j<col;j++){
                int tmp = m[i-1][j];
                if(j-1>=0){
                    tmp = min(tmp, m[i-1][j-1]);
                }
                if(j+1<col){
                    tmp = min(tmp, m[i-1][j+1]);
                }
                m[i][j] +=tmp;
            }
        }
        return *min_element(m[row-1].begin(), m[row-1].end());
    }

    void rec(vector<vector<int>> m, int i, int j){
        if(dp[i][j]!=INT_MAX){
            return;
        }

        if(i>=row){
            return;
        }
        rec(m, i+1, j);
        int tmp = dp[i+1][j];

        if(j-1>=0 && j-1<col){
            rec(m, i+1, j-1);
            tmp = min(tmp, dp[i+1][j-1]);
        }
        if(j+1>=0 && j+1<col){
            rec(m, i+1, j+1);
            tmp = min(tmp, dp[i+1][j+1]);
        }
        dp[i][j] = m[i][j] + tmp;

    }

    //Works fine, but gives TLE
    int minFallingPathSumRec(vector<vector<int>>& m) {
        row = m.size();
        col = m[0].size();
        dp.assign(row, vector<int>(col, INT_MAX));
        dp[row-1] = m[row-1];
        for(int j=0; j<col; j++){
            rec(m, 0, j);
        }
        //pp(dp[0]);
        return *min_element(dp[0].begin(), dp[0].end());
    }
    void pp(vector<int> v){
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

