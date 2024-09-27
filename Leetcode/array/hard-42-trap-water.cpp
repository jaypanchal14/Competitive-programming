#include<iostream>
#include<vector>

using namespace std;

/*
Description :
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:

    int trapTwoPointers(vector<int>& h) {
        int ans = 0, l = 0, r = h.size()-1;
        int lmax = 0, rmax = 0;
        while(l<=r){
            if(h[l] <= h[r]){
                if(lmax < h[l]){
                    lmax = h[l];
                }else{
                    ans += lmax-h[l];
                    l++;
                }
            }else{
                if(rmax < h[r]){
                    rmax = h[r];
                }else{
                    ans += rmax-h[r];
                    r--;
                }
            }
        }
        return ans;
    }

    int trap(vector<int>& h) {
        int ans = 0;
        int s = h.size();
        int i = 1, end = -1;
        int start = 0;
        while(i<s){
            if(h[start]>h[i]){
                i++;
            }else{
                end = i;
                int tmp = 0;
                for(int k=start+1; k<end;k++){
                    tmp += h[k];
                }
                ans += min(h[start],h[end])*(end-start-1)-tmp;
                start = i;
                i++;
                end = -1;
            }
        }
        if(start<s-1){
            //If it comes here, it means, we have come across a bar which is large and starting position, and all the bars after it, are smaller in magnitude
            int j = s-2;
            end = s-1;
            while(j>=start){
                if(h[j]>h[end]){
                    int tmp = 0;
                    for(int k=end-1; k>j;k--){
                        tmp += h[k];
                    }
                    ans += min(h[j],h[end])*(end-j-1)-tmp;
                    end = j;
                    j--;
                }else{
                    j--;
                }
            }

        }

        return ans;
    }
};