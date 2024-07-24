#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/*
Description:
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
Each Ai or Bi is a string that represents a single variable.
You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Example:
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string, vector<pair<string, double>>> m;
        
        //Storing the value for each respective equations
        for(int i=0; i<v.size(); i++){
            m[eq[i][0]].push_back({eq[i][1], v[i]});
            m[eq[i][1]].push_back({eq[i][0], 1 / v[i]});
        }
        vector<double> ans(q.size());
        for(int i=0; i<q.size(); i++){
            unordered_set<string> st;
            //applying dfs for each query
            ans[i] = dfs(m, q[i][0], q[i][1], st);
        }
        return ans;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>>& m, string start, string end, unordered_set<string>& st){
        //variable not found
        if(m.find(start)==m.end() || m.find(end)==m.end()){
            return -1;
        }

        //end variable found
        if(start == end){
            return 1;
        }
        st.insert(start);
        double res = -1;
        for(auto& p : m[start]){
            if(st.count(p.first)){
                continue;
            }
            res = dfs(m, p.first, end, st);
            if(res != -1){
                return p.second * res;
            }
        }
        return -1;
    }
};