#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
Description:
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.
You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
The matrix should also satisfy the following conditions:
The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

Example:
Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]

Approach:
1) Find the topological sort from the given mappings.
2) If there is any cycle detected, return not possible.
3) Based on topo-order of both the rows and columns, assign the value in the ans matrix.

*/

class Solution {
public:

    vector<int> visited;
    vector<int> called;

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        visited.resize(k+1, 0);
        called.resize(k+1, 0);
        vector<int> rows, cols;
        bool flag = getTopo(rows, rowConditions, k);
        if(flag){
            // cout<<"Caught cycle in row";
            return {};
        }
        for(int i=1; i<=k; i++){
            visited[i] = 0;
            called[i] = 0;
        }
        flag = getTopo(cols, colConditions, k);
        if(flag){
            // cout<<"Caught cycle in col";
            return {};
        }
        vector<vector<int>> ans(k, vector<int> (k,0));
        int val;
        int i, j;
        for(i=0; i<k; i++){
            visited[rows[i]-1] = i;
            called[cols[i]-1] = i;
        }
        for(int i=0; i<k; i++){
            ans[visited[i]][called[i]] = i+1;
        }
        return ans;
    }

    bool getTopo(vector<int>& v, vector<vector<int>>& cond, int& k){
        vector<unordered_set<int>> adj(k+1);
        for(vector<int>& e : cond){
            adj[e[0]].insert(e[1]);
        }
        
        for(int i=1; i<=k; i++){
            if(!visited[i]){
                if(dfs(i, adj, v)){
                    return true;
                }
            }
        }
        reverse(v.begin(), v.end());
        return false;
    }

    bool dfs(int i, vector<unordered_set<int>>& adj, vector<int>& v){
        visited[i] = 1;
        called[i] = 1;
        for(auto& next : adj[i]){
            if(!visited[next]){
                if(dfs(next, adj, v)){
                    return true;
                }
            }
            else if(called[next]){
                return true;
            }
        }
        called[i] = 0;
        v.emplace_back(i);
        return false;
    }
};