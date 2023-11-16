#include<iostream>
#include<vector>

using namespace std;

/*
Description:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
*/

//Bottom up
int costTab(vector<int> v, int n){
    
    vector<int> dp(n+1);
    dp[0] = v[0];
    dp[1] = v[1];

    for(int i = 2; i< v.size(); i++){
        dp[i] = v[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

//Top-to-bottom method
int cost(vector<int> v, int currentStair, vector<int> &dp){
    if (currentStair <= 1){
        return v[currentStair];
    }

    if(dp[currentStair] != -1){
        return dp[currentStair];
    }

    dp[currentStair] =  min(cost(v, currentStair-1, dp), cost(v, currentStair-2, dp)) + v[currentStair];
    return dp[currentStair];
}

// Using recursion only (Will give TLE)
int costUsingRecursion(vector<int> v, int currentStair){
    if (currentStair <= 1){
        return v[currentStair];
    }
    return min(costUsingRecursion(v, currentStair-1), costUsingRecursion(v, currentStair-2)) + v[currentStair];
}

int main(){
    vector<int> stairs = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int s = stairs.size();

    //With recursion
    //cout<<"Min cost to reach top is: "<<min(costUsingRecursion(stairs,s-1), costUsingRecursion(stairs, s-2));
    vector<int> dp(s+1, -1);
    //Using memoization
    //cout<<"Min cost to reach top is: "<<min(cost(stairs, s-1, dp), cost(stairs, s-2, dp));
    
    //Using tabulation
    cout<<"Min cost to reach top is: "<<costTab(stairs, s);
    return 0;
}