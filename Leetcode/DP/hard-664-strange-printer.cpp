#include<iostream>
#include<vector>

using namespace std;

/*
Description:
There is a strange printer with the following two special properties:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example:
Input: s = "abcababa"
Output: 5
Explanation:
The printer needs to print the string as follows:
1st turn: "a" (1 turn) : aaaaaaaa
2nd turn: "b" (1 turn) : abbbbbba
3rd turn: "c" (1 turn) : abcbbbba
4th turn: "a" (1 turn) : abcabbba
5th turn: "a" (1 turn) : abcababa

*/

class Solution {
public:
    int strangePrinter(string s) {
        //Pre-process to remove duplicates (Optimization)
        //As, aaaa and a both required 1 operation
        s = removeDuplicates(s);
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return get(0, n-1, s, dp);
    }

    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }

    int get(int start, int end, string& s, vector<vector<int>>& dp){
        if(start>end){
            return 0;
        }
        if(start==end){
            return 1;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = end-start+1;
        ans = min(ans, 1+get(start+1, end, s, dp));
        for(int i=end; i>start; i--){
            if(s[i]==s[start]){
                //Any from both the below will work
                // ans = min(ans, get(start, i-1, s, dp) + get(i+1, end, s, dp));
                ans = min(ans, get(start+1, i, s, dp) + get(i+1, end, s, dp));
            }
        }
        return dp[start][end] = ans;
    }
};