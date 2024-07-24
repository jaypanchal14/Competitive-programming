#include<iostream>
#include<vector>

using namespace std;
/*
Decription:
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.
Example:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/
class Solution {
public:
    //Parent vector
    vector<int> v;

    //Find the parent of current node
    int find(int i){
        if(v[i]==-1){
            return i;
        }
        return v[i]=find(v[i]);
    }

    //Unite two node, and update the parent of first node
    void union_f(int x, int y){
        int xi = find(x);
        int yi = find(y);
        v[xi] = yi;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        v.resize(n+1, -1);
        int a,b;
        for(auto& e : edges){

            //Disjoint set
            a = find(e[0]);
            b = find(e[1]);
            if(a==b){
                //Anamoly found or cycle found
                return e;
            }
            union_f(e[0], e[1]);
        }
        return {};
    }
};