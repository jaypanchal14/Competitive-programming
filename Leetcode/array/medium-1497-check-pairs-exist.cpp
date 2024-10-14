#include<vector>
#include<unordered_map>
using namespace std;

/*
Description:
Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.

Example:
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;

        //Get the frequency of the elements in range of [0, k)
        for(int& num : arr){
            //we are doing two time modulo, to get rid of negative reminder
            m[((num % k)+k)%k]++;
        }
        int other;
        for(auto& p : m){
            other = (k - p.first) % k;
            //If key is equal, then it should be even
            if(other == p.first){
                if(m[other] & 1){
                    return false;
                }
            }
            //If we have the complement, it should have equal frequency
            if(m[other]!=m[p.first]){
                return false;
            }
        }
        return true;
    }
};