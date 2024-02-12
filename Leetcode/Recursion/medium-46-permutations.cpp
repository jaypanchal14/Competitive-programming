#include <iostream>
#include <vector>

using namespace std;

/*
Description : 
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
here, nums[i] belongs to[-10,10]

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void gg(vector<int> &nums, int current, vector<vector<int>> &ans){
    if (current == nums.size() - 1){
        ans.push_back(nums);
        return;
    }
    for (int i = current; i < nums.size(); i++){
        swap(nums[i], nums[current]);
        gg(nums, current + 1, ans);
        swap(nums[i], nums[current]);
    }
}

void get(vector<int> &nums, vector<int> tmp, int current, vector<vector<int>> &ans){
    if (current == nums.size()){
        if (tmp.size() > 0){
            ans.push_back(tmp);
        }
        return;
    }
    int tt = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != 11){
            tmp.push_back(nums[i]);
            tt = nums[i];
            nums[i] = 11;
            get(nums, tmp, current + 1, ans);
            nums[i] = tt;
            tmp.pop_back();
        }
    }
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    //get(nums, {}, 0, ans);
    gg(nums, 0, ans);
    for(auto v : ans){
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}