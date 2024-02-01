#include <iostream>
#include <vector>

using namespace std;

/*
Description :
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
1)Integers in each row are sorted in ascending from left to right.
2)Integers in each column are sorted in ascending from top to bottom.
*/

bool searchMatrix(vector<vector<int>> &m, int t)
{
    int r = m.size();
    int c = m[0].size();
    int row = r - 1, col = 0;
    while (row >= 0 && col < c){
        int target = m[row][col];
        if (target == t){
            return true;
        }
        else if (target > t){
            row--;
        }
        else{
            col++;
        }
    }
    return false;
}