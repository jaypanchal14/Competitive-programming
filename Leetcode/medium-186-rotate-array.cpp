#include<iostream>
#include<vector>
using namespace std;

/*
Description:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Input: 
nums = [1,2,3,4,5,6,7], k = 3
Output: 
nums = [5,6,7,1,2,3,4]
*/

void reverse(vector<int>& nums, int start, int end){
    while(start<=end){
        swap(nums[start++],nums[end--]);
    }
}

void rotate(vector<int>& nums, int k) {
    vector<int> v;
    int s = nums.size();
    k = k%s;
    for(int i = 0; i<s;i++){
        v.push_back(nums[(i+s-k)%s]);
    }
    nums = v;
}

int main(){

    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;
    int size = v.size();
    //rotate(v, 4);
    k = k%size;
    reverse(v, 0, k);
    reverse(v,k+1,size-1);
    reverse(v, 0, size-1);

    cout<<"After 4 right-rotate:"<<endl;
    for(int a : v){
        cout<<a<<" ";
    }

    return 0;
}