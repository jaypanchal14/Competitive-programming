#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
Description:
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. 
You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
*/

class Solution {
public:

    vector<int> parent;

    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void union_f(int i, int j){
        int a = find(i);
        int b = find(j);
        if(a==b){
            return;
        }
        parent[b] = a;
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        if(n-1 > c.size()){
            return -1;
        }
        //Using DFS
        /*unordered_map<int, vector<int>> m;
        for(auto& edge : c){
            m[edge[0]].emplace_back(edge[1]);
            m[edge[1]].emplace_back(edge[0]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, m, visited);
                ans++;
            }
        }*/

        //Using disjoint set
        parent.resize(n+1, -1);
        for(auto& edge : c){
            union_f(edge[0], edge[1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(parent[i]==-1){
                ans++;
            }
        }
        return ans>1 ? ans-1: 0;
    }

    void dfs(int i, unordered_map<int, vector<int>>& m, vector<bool>& visited){
        visited[i] = true;
        for(auto& next : m[i]){
            if(!visited[next]){
                dfs(next, m, visited);
            }
        }
    }
};