#include<vector>
#include<iostream>

using namespace std;

/*
Description:
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land).
An island is a group of 1's connected 4-directionally (horizontal or vertical).
Any cells outside of the grid are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
Return the number of islands in grid2 that are considered sub-islands.
Example:
Input: 
grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3

*/

class Solution {
public:

    int m, n;
    vector<int> dir = {0,1,0,-1,0};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int ans = 0, tmp;
        //Logic step-1 : Fill 0's in grid2 whenever there's 0 in same cell in grid1
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] && grid1[i][j]==0){
                    fill(i, j, grid2);
                }
            }
        }
        //step-2 : Apply DFS on the remaining island and increse the counter
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] && grid1[i][j]){
                    ans++;
                    dfs(i, j, grid1, grid2);
                    
                }
            }
        }

        //Another method, which combines both first and second step into a single step
        /*
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j]){
                    tmp = 1;
                    dfsWithTmp(i, j, grid1, grid2, tmp);
                    if(tmp==1){
                        ans++;
                    }                    
                }
            }
        }
        */

        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2){
        int x, y;
        g2[i][j] = 0;
        for(int d=0; d<4;d++){
            x = i+dir[d];
            y = j+dir[d+1];
            if(x>=0 && x<m && y>=0 && y<n){
                if(g1[x][y] && g2[x][y]){
                    dfs(x, y, g1, g2);
                }
            }
        }
    }

    void dfsWithTmp(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2, int& tmp){
        int x, y;
        //If there is no filled cell in grid1, then this is not the correct sub-island from grid2
        if(g1[i][j]==0){
            tmp = 0;
        }
        g2[i][j] = 0;
        
        //Fill all the connected cells as '0'
        for(int d=0; d<4;d++){
            x = i+dir[d];
            y = j+dir[d+1];
            if(x>=0 && x<m && y>=0 && y<n){
                if(g2[x][y]){
                    dfsWithTmp(x, y, g1, g2, tmp);
                }
            }
        }
    }

    void fill(int i, int j, vector<vector<int>>& g2){
        int x, y;
        g2[i][j] = 0;
        for(int d=0; d<4;d++){
            x = i+dir[d];
            y = j+dir[d+1];
            if(x>=0 && x<m && y>=0 && y<n){
                if(g2[x][y]){
                    fill(x, y, g2);
                }
            }
        }
    }

    void print(vector<vector<int>>& g){
        for(auto& row : g){
            for(auto& x : row){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};