#include <iostream>
#include <vector>

using namespace std;

/*
Description : You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
*/

bool searchMatrix(vector<vector<int>> &m, int t)
{
    int r = m.size();
    int c = m[0].size();
    int last = r * c - 1;
    int first = 0;
    while (first <= last){
        int mid = (last - first) / 2 + first;
        int row = mid / c;
        int col = mid % c;
        if (m[row][col] == t){
            return true;
        }
        else if (m[row][col] > t){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    return false;
}