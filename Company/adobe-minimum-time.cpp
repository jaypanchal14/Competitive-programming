#include<iostream>
#include<vector>
#include<climits>

using namespace std;

/*
Geek, being the brightest student of the class, is given the task to solve n puzzles by his teacher in minimum possible time. 
The puzzles are numbered from 1 to n and he has to complete them in the order of their numbers. 
Geek can solve a puzzle in two ways: either solve it on his own or copy from his book. 
As Geek is busy these days, he has asked for help to calculate the minimum possible time in which he can solve all puzzles in the given order.
Geek has provided:
An array of integers time[] of size n, where time[i] tells the time Geek would take to solve the ith puzzle on his own.
An integer array search[] of size n, where search[i] represents the time Geek will take to search for the ith puzzle in his book. 
When Geek searches for the ith puzzle in his book, he also gets to know the answers for the next k puzzles 
(including the ith puzzle). 
If less than k puzzles remain after i, he gets answers for all remaining puzzles including i. 
After the search, he can directly jump to any puzzle (i+j)th where 1≤j≤min(k,n−i) by copying answers of all puzzles from index 
i to (i+j−1).
Your task is to determine the minimum time Geek will take to solve all puzzles.
*/

class Solution {
  public:
    int minTime(int n, vector<int> &time, vector<int> &search, int k) {
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=time[i] + dp[i+1];
            int mini=INT_MAX;
            for(int j=i+1;j<=min(i+k,n);j++){
                mini=min(mini,dp[j]);
            }
            if(mini!=INT_MAX){
                dp[i]=min(dp[i],search[i]+mini);
            }
        }
        return dp[0];
    }
};

