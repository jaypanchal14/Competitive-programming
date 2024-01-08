#include<iostream>
#include<vector>

using namespace std;

/*
Description : A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
*/

int numDecodings(string s) {
        int size = s.size();
        vector<int> ways(size, 0);
        if(s[0] == '0'){
            return 0;
        }else{
            ways[0] = 1;
        }
        if(size==1){
            return ways[0];
        }
        if(s[1] == '0'){
            if((s[0]-'0')*10<= 26){
                ways[1] = 1;
            }
            else{
                return 0;
            }
        }else{
            if((s[0]-'0')*10+(s[1]-'0') <= 26){
                ways[1] = 2;
            }else{
                ways[1] = 1;
            }
        }
        for(int i=2; i<size; i++){
            if(s[i]=='0'){
                if(s[i-1]=='0'){
                    return 0;
                }
                if((s[i-1]-'0')*10<= 26){
                    ways[i] = ways[i-2];
                }
                else{
                    return 0;
                }
            }else{
                if(s[i-1]=='0'){
                    ways[i] = ways[i-1];
                    continue;
                }
                if((s[i-1]-'0')*10+(s[i]-'0') <= 26){
                    ways[i] = ways[i-1] + ways[i-2];
                }else{
                    ways[i] = ways[i-1];
                }
            }
        }
        return ways[size-1];
    }

int main(){

    string s = "12010";

    cout<<numDecodings(s);

    return 0;
}