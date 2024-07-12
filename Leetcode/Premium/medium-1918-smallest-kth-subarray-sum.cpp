#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <numeric>

using namespace std;

/*
Description:
Given an integer array nums of length n and an integer k, return the k-th smallest subarray sum.
A subarray is defined as a non-empty contiguous sequence of elements in an array.
A subarray sum is the sum of all elements in the subarray.
Example:
Input: nums = [2,1,3], k = 4
Output: 3
*/


// Similarly they can ask for kth largest number,
// we can use min-heap to store the largest k subarray sum.


// Time-complexity : O(n^2)
int kthSmallestSubarraySum(vector<int>& nums, int k){
    int n = nums.size();
    int sum;
    //This will only store first k subarray sum
    priority_queue<int> q;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(q.size() < k) {
                q.push(sum);
            }else{
                if(sum < q.top()) {
                    q.pop();
                    q.push(sum);
                }
                    
            }
        }
    }
    cout<<endl;
    return q.top();
}

int check(const vector<int>& nums, int m) {
    int res = 0;
    int sum = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
        sum += nums[r];
        while (sum > m)
            sum -= nums[l++];
        res += r - l + 1;
    }
    return res;
  }

int kthSmallestSubarraySumBS(vector<int>& nums, int k){
    int n = nums.size();
    int left = *min_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);
    int mid;
    while(left<right){
        mid = left + (right-left)/2;
        if(check(nums, mid) >= k){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}
int main(){
    vector<int> nums = {3,-2,5,1};
    int k = 1;
    int ans = kthSmallestSubarraySum(nums, k);
    // int ans = kthSmallestSubarraySumBS(nums, k);
    cout <<"Kth smallest sub-array sum is: "<< ans << endl;
    return 0;
}