#include <iostream>
#include <vector>

using namespace std;

/*
Description :
Given an integer array nums, return the number of all the arithmetic subsequences of nums.
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
*/

class Solution {
public:

    int get(int pos, int index, int dif, int s, vector<int> n){
        if(index >= s){
            return 0;
        }
        int tmp = 0;
        //Taken
        if(n[pos] - n[index] == dif){
            tmp = 1 + get(index, index+1, dif, s, n);
        }
        //Not taken
        tmp += get(pos, index+1, dif, s, n);
        return tmp;
    }

    int numberOfArithmeticSlices(vector<int>& n) {
        int s = n.size();
        if(s<3){return 0;}
        vector<int> v(s,0);
        int ans = 0;
        for(int i=0; i<s-2; i++){
            for(int k=i+1;k<s-1;k++){
                ans += get(k, k+1, n[i]-n[k], s , n);
            }
        }
        return ans;
    }
};