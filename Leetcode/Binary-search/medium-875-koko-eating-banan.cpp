#include<iostream>
#include<vector>
#include<algorithm>

/*
Description:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, 
she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Input: piles = [3,6,7,11], h = 8
Output: 4
*/

using namespace std;

class Solution {
public:

    int check(int mid, vector<int> p, int h){
        long long count = 0;
        for(int i:p){
            count += (i/mid);
            if(i%mid>0){
                count++;
            }
        }
        if(count>h){
            return 0;
        }else{
            return 1;
        }
    }

    int minEatingSpeed(vector<int>& p, int h) {
        int s = p.size();
        if(s==1){
            return (p[0]/h)+(p[0]%h==0?0:1);
        }
        int ans = 0;
        int start = 1;
        int end = *max_element(p.begin(), p.end());
        while(start<=end){
            int mid = (end-start)/2+start;
            if(check(mid, p, h)==1){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};