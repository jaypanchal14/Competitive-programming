#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
*/

class Solution {
public:

    //count how many pairs are having less or equal distance compared to mid distance
    int check(vector<int>& nums, int mid, int& n){
        int c = 0, j = 0;
        for(int i=0; i<n; i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
            }
            c += (j-i-1);
        }
        return c;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n-1]-nums[0], mid;
        int ans = right, count;
        while(left<=right){
            mid = left + (right-left)/2;
            count = check(nums, mid, n);
            if(count>=k){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
        /*
        //Gives TLE
        priority_queue<int> q;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                q.push(abs(nums[i]-nums[j]));
                if(q.size()>k){
                    q.pop();
                }
            }
        }
        return q.top();
        */
    }
};