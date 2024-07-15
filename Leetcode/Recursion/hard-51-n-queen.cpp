#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
Description:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Example:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

class Solution {
public:

    //Optimized approach
    unordered_map<int, bool> col;
    unordered_map<int, bool> left;
    unordered_map<int, bool> right;

    //Driver-class with Time complexity: O(n^2)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> t(n, string(n,'.'));
        get(0, n, t, ans);
        return ans;
    }

    void get(int row, int& n, vector<string>& t, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(t);
            return;
        }
        for(int i=0; i<n; i++){
            // if(check(row, i, n, t)){
            if(col[i]==false && left[n-1+row-i]==false && right[row+i]==false){
                t[row][i] = 'Q';
                col[i] = true;
                left[n-1+row-i] = true;
                right[row+i] = true;
                get(row+1, n, t, ans);
                col[i] = false;
                left[n-1+row-i] = false;
                right[row+i] = false;
                t[row][i] = '.';
            }
        }
    }

    bool check(int& i, int& j, int& n, vector<string>& t){
        //To check if there is any queen placed in same columns
        if(col[j]){
            return false;
        }

        //This will check for the left-diagonal, (n-1+i-j) will always return same value for the whole left-diagonal
        if(left[n-1+i-j]){
            return false;
        }

        //This will check for the right-diagonal, i+j will be same for the right diagonal
        if(right[i+j]){
            return false;
        }
        return true;
    }
};