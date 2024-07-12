#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

/*
Description :
You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9].
You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
You are restricted with the following rules:
The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.

Example :
Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
*/

class Solution {
public:

    vector<char> op = {'+','-','*','/'};

    bool judgePoint24(vector<int>& cards) {
        vector<float> v;
        for(auto& a : cards){
            v.emplace_back(1.0 * a);
        }
        return solve(v);
    }

    bool solve(vector<float> v){
        if(v.size()==1){
            return abs(v[0]-24)<0.0001;
        }
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(i!=j){
                    vector<float> nv;
                    for(int k=0; k<v.size(); k++){
                        if(k!=i && k!=j){
                            nv.emplace_back(v[k]);
                        }
                    }

                    for(char& c : op){
                        if(c=='+'){
                            nv.emplace_back(v[i]+v[j]);
                        }
                        else if(c=='-'){
                            nv.emplace_back(v[i]-v[j]);
                        }
                        else if(c=='*'){
                            nv.emplace_back(v[i]*v[j]);
                        }
                        else{
                            if(v[j]==0){
                                continue;
                            }
                            nv.emplace_back(v[i]/v[j]);
                        }
                        if(solve(nv)){
                            return true;
                        }
                        nv.pop_back();
                    }

                }
            }

        }
        return false;
    }
};