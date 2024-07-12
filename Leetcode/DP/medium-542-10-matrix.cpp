#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Description :
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]){
                    dp[i][j] = m*n;
                }else{
                    dp[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int x, y, nx, ny;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                nx = x + dir[i];
                ny = y + dir[i+1];
                if(nx >=0 && nx < m && ny >= 0 && ny < n && dp[nx][ny] > 1 + dp[x][y]){
                    q.push({nx, ny});
                    dp[nx][ny] = 1 + dp[x][y];
                }
            }
        }
        return dp;
    }
};