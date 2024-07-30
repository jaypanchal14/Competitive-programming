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
    vector<int> coins = {3,4,5};
    int amount = 11;
    int s = coins.size();
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    /*for(int i = 0; i < s; i++){
        for(int j = 1; j<amount+1; j++){
            if( coins[i] <=j && dp[j-coins[i]]!=INT_MAX && dp[j] > 1 + dp[j-coins[i]]){
                dp[j] = 1 + dp[j-coins[i]];
            }
        }
        
    }*/

    
    for(int i=1; i<=amount; i++){
        for(auto& c : coins){
            if(i>=c && dp[i-c]!=INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-c]);
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