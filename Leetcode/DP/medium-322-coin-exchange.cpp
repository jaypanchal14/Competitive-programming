#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*
Description:
Given an array of coins available, return the minimum number of coints required to get the target amount.
Input: coins = [1,2,5], amount = 11
Output: 3
*/

int main(){
    vector<int> coins = {2,3,5,6};
    int amount = 7;
    int s = coins.size();
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < s; i++){
        for(int j = 1; j<amount+1; j++){
            if( coins[i] <=j && dp[j-coins[i]]!=INT_MAX && dp[j] > 1 + dp[j-coins[i]]){
                dp[j] = 1 + dp[j-coins[i]];
            }
        }
        
    }
    if(dp[amount]!=INT_MAX){
        cout<<"Answer is: "<<dp[amount];
    }else{
        cout<<"Answer is not possible";
    }
    return 0;   
}