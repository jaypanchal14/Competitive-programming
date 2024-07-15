#include<iostream>
#include<vector>

using namespace std;

/*
Description:
Write a program to solve a Sudoku puzzle by filling the empty cells.
Example:
Input: board = [
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
Output: [
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
*/
class Solution {
public:

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(check(i, j, k, board)){
                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //1st approach
        //solve(board);

        //2nd approach
        int r = -1, c = -1, count = 0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    count++;                    
                    if(r==-1){
                        r = i;
                        c = j;
                    }
                }
            }
        }
        if(r==-1){
            return;
        }
        bool flag = false;
        count--;
        for(char k='1'; k<='9'; k++){
            if(check(r, c, k, board)){
                board[r][c] = k;
                if(count==0){
                    return;
                }
                get(r, count, flag, board);
                if(flag){
                    return;
                }
                board[r][c] = '.';
            }
        }
    }

    void get(int row, int& count, bool& flag, vector<vector<char>>& board){
        for(int i=row; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    continue;
                }
                for(char k='1'; k<='9'; k++){
                    if(check(i, j, k, board)){
                        count--;
                        board[i][j] = k;
                        if(count==0){
                            flag = true;
                            return;
                        }
                        get(i, count, flag, board);
                        if(flag){
                            return;
                        }
                        board[i][j] = '.';
                        count++;
                    }
                }
                //Because the last updated cell is not correct
                return;
            }
        }
    }

    bool check(int& row, int& col, char val, vector<vector<char>>& board){

        //for checking in the grid-box
        int r = (row/3)*3;
        int c = (col/3)*3;

        for(int i=0; i<9; i++){
            if(board[i][col]==val || board[row][i]==val || board[r+(i/3)][c+(i%3)]==val){
                return false;
            }
        }
        return true;
    }
};