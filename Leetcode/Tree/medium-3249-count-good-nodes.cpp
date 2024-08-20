#include<vector>
#include<iostream>

using namespace std;

/*
Description:
There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. 
You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
A node is good if all the subtrees rooted at its children have the same size.
Return the number of good nodes in the given tree.
A subtree of treeName is a tree consisting of a node in treeName and all of its descendants.

Example:
Input: edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]
Output: 12
*/

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        int ans = 0;
        vector<vector<int>> v(n);
        for(auto& e : edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        get(0, -1, v, ans);
        return ans;
    }

    int get(int root, int par, vector<vector<int>>& v, int& ans){
        if(v[root].size()==1 && v[root][0]==par){
            ans++;
            return 1;
        }
        int tmp;
        int x = -1, child = 0;
        bool flag = true;
        for(int& n : v[root]){
            if(n!=par){
                tmp = get(n, root, v, ans);
                child += tmp;
                if(x==-1 || x == tmp){
                    x = tmp;
                }else{
                    flag = false;
                }
            }
            
        }
        if(flag){
            ans++;
        }
        return child+1;
    }

};