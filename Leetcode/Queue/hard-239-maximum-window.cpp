#include<queue>
#include<vector>

using namespace std;

/*
Description:
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.
Return the max sliding window.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i=0; i<nums.size(); i++){

            if(!q.empty() && q.front()==i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i-k>=-1){
                ans.emplace_back(nums[q.front()]);
            }
        }
        return ans;
    }
};