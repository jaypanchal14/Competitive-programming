#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
Given an array of integers nums, find the next permutation of nums.

Example:
Input : [28,5,10,9,6]
Output : [28,6,5,9,10]
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1,n = nums.size();
        for(int i=n-2; i>=0; i--){
            //Find the break point
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1; i>index;i--){
            //Replace with first largest
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        //reverse the remaining tail
        reverse(nums.begin()+index+1, nums.end());
    }
};