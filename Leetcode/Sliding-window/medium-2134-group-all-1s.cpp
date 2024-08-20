#include<vector>

using namespace std;

/*
Description:
A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

Example:
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]){
                count++;
            }
        }
        int tmp = 0;
        //Consider for the first window of size count
        for(int i=0; i<count; i++){
            if(nums[i]){
                tmp++;
            }
        }
        int ans = count-tmp;
        for(int i=count; i<n+count; i++){
            if(nums[i-count]){
                tmp--;
            }
            if(i>=n){
                if(nums[i%n]){
                    tmp++;
                }
                ans = min(ans, count-tmp);
            }else{
                if(nums[i]){
                    tmp++;
                }
                ans = min(ans, count-tmp);
            }
        }
        return ans;
    }
};