#include <iostream>
#include <vector>

using namespace std;

/*
Description :
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
Given an integer array nums, return the number of arithmetic subarrays of nums.
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
*/

int numberOfArithmeticSlices(vector<int> &n)
{
    int s = n.size();
    if (s < 3){
        return 0;
    }
    vector<int> v(s, 0);

    for (int i = 0; i < s - 2; i++){
        int dif = n[i] - n[i + 1];
        for (int j = i + 1; j < s - 1; j++){
            if (dif == n[j] - n[j + 1]){
                v[i]++;
            }
            else{
                break;
            }
        }
    }

    int ans = 0;
    for (int a : v){
        ans += a;
    }
    return ans;
}