#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Description : (Without sorting)
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Example :
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/
class Solution {
public:

    int ans;

    int findKthLargest(vector<int>& nums, int k) {
        /*
        //With quick-select
        ans = -1;
        quick(nums, 0, nums.size()-1, k);
        for(int& a : nums){
            cout<<a<<" ";
        }
        return ans;
        */
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        for(int i=0; i<n; i++){
            q.push(nums[i]);
            if(q.size()>k){
                q.pop();
            }
        }
        return q.top();
    }

    void quick(vector<int>& nums, int i, int j, int k){
        if(i>j){
            return ;
        }
        if(ans != -1){
            return;
        }
        int pivot = find(nums, i, j);
        if(pivot-i == k-1){
            ans = nums[pivot];
            return;
        }
        if(pivot-i > k-1){
            quick(nums, i, pivot-1, k);
        }else{
            quick(nums, pivot+1, j, k-pivot-1+i);
        }
    }

    int find(vector<int>& nums, int i, int j){
        if(i>=j){ return i;}
        int start = i+1;
        while(start<=j){
            if(nums[i] <= nums[start]){
                start++;
            }else{
                swap(nums[start], nums[j--]);
            }
        }
        swap(nums[i], nums[j]);
        return j;
    }
};