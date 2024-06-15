#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
Description :
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, 
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, 
it can only finish at most k distinct projects before the IPO. 
Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

Example :
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int size = capital.size();
        vector<pair<int,int>> v;
        for(int i=0; i<size; i++){
            v.emplace_back(capital[i], profits[i]);
        }
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int i=0;
        for(int j=0; j<k; j++){

            while(i<size && w>=v[i].first){
                q.push(v[i].second);
                i++;
            }

            if(q.empty()){
                break;
            }

            w += q.top();
            q.pop();
        }
        return w;
    }
};
