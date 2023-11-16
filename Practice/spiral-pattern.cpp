#include<iostream>
#include<vector>
using namespace std;

/*
Description:
Given a matrix of size r*c. Traverse the matrix in spiral form.
Input :
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output : 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

int main(){

    vector<vector<int>> matrix {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> res;
    vector<vector<int>> vis(r, vector<int> (c,0));
    vector<int> cr = {0,1,0,-1};
    vector<int> cc = {1,0,-1,0};
    int i=0, j=0;
    int index = 0;
    while(i>-1 && i < r && j >-1 && j<c && vis[i][j]!=1){
        
        int row = cr[index];
        int column = cc[index];
        if(row == 0){
            for(;j>-1 && j<c && vis[i][j]!=1;j+=column){
                res.push_back(matrix[i][j]);
                vis[i][j] = 1;
            }
            index++; j-=column;
            index = index % 4;
            i = i + cr[index];
        }else{
            for(;i>-1 && i<r && vis[i][j]!=1;i+=row){
                res.push_back(matrix[i][j]);
                vis[i][j] = 1;
            }
            index++; i-=row;
            index = index % 4;
            j = j + cc[index];

        }
    }
    for(auto xx: res){
        cout<<xx<<" ";
    }
    return 0;
}