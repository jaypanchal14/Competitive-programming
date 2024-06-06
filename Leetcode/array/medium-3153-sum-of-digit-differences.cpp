#include<iostream>
#include<vector>

using namespace std;

/*
Description :
You are given an array nums consisting of positive integers where all integers have the same number of digits.
The digit difference between two integers is the count of different digits that are in the same position in the two integers.
Return the sum of the digit differences between all pairs of integers in nums.

Input: nums = [13,23,12]
Output: 4
*/

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        string tmp;
        int arr[10][10] = {0};
        for(int i=0; i<nums.size(); i++){
            tmp = to_string(nums[i]);
            for(int j=0; j<tmp.size(); j++){
                ans += i-arr[j][tmp[j]-'0'];
                arr[j][tmp[j]-'0']++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v = {20,14,23,56,87,34,63,99,11};
    cout<<"Sum of difference: "<<s.sumDigitDifferences(v)<<endl;

    return 0;
}