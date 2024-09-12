#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites 
where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        unordered_set<int> s;
        vector<bool> p(num,false);
        for(int i=0; i<num; i++){
            if(s.count(i)){
                continue;
            }else{
                if(dfs(adj, s, i, p)){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adj, unordered_set<int>& s, int i, vector<bool>& p){
        if(s.count(i)){
            return true;
        }
        s.insert(i);
        p[i] = true;
        for(int& next : adj[i]){
            if(s.count(next)==0 && dfs(adj, s, next, p)){
                return true;
            }
            if(p[next]){
                return true;
            }
        }
        p[i] = false;
        return false;
    }
};