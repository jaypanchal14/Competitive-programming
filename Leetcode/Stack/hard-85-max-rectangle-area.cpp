#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/*
Description :
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example :
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        int result = 0;
        vector<int> hist(matrix[0].size());

        for (const vector<char>& row : matrix) {
            for (int i = 0; i < row.size(); ++i)
                hist[i] = row[i] == '0' ? 0 : hist[i] + 1;

            //Using histogram area logic from the 1D vector
            result = max(result, largestarea(hist));
        }

        return result;
    }
private:
    int largestarea(const vector<int>& heights) {
        int result = 0;
        stack<int> stack;

        for (int i = 0; i <= heights.size(); ++i) {
            while (!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i])) {
                const int m = heights[stack.top()];
                stack.pop();
                const int v = stack.empty() ? i : i - stack.top() - 1;
                result = max(result, m * v);
            }
            stack.push(i);
        }

        return result;
    }
};