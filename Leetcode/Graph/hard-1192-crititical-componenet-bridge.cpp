#include<iostream>
#include<vector>

using namespace std;

/*
Description:
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. 
Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.

Approach : Tarjan's algorithm

Example:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
*/
class Solution {
public:
    vector<int> low, discover;
    vector<bool> visited;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> ans;
        //Based on the constraint
        low.resize(n, 1000000);
        discover.resize(n, 1000000);
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(auto& e: c){
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int time = 0;
        dfs(0, -1, time, adj, ans);
        return ans;
    }

    void dfs(int node, int parent, int& time, vector<vector<int>>& adj, vector<vector<int>>& ans){
        visited[node] = true;
        low[node] = time;
        discover[node] = time;
        time++;
        for(auto& next : adj[node]){
            if(next==parent){
                continue;
            }
            if(visited[next]==false){
                dfs(next, node, time, adj, ans);
                //Update the low of current node from neighbours, if caught any backedge
                low[node] = min(low[node], low[next]);
                //If the discovery time of the parent is lower than lowest time of neighbour
                //we have got the back edge
                if(low[next] > discover[node]){
                    ans.push_back({node, next});
                }
            }else{
                //If the node is already visited, it means this is the back edge
                //edge creating a cycle
                low[node] = min(low[node], discover[next]);
            }
        }
    }
};