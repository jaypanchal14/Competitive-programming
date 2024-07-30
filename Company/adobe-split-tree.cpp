#include<iostream>
#include<vector>
#include<climits>

using namespace std;

/*
Description:
Given a tree with n nodes and n-1 edges. Each node in the tree has a weight assigned to it. 
The value of the tree is determined by adding up the weights of all the nodes in the tree. The weight of ith node is i.
Your task is to divide the tree into two separate trees by removing one of the edges. 
The goal is to find the best way to split the tree so that the absolute difference in values between the two resulting trees is as small as possible.
Find the minimum difference of the values of the two trees after splitting the original tree.

Note: Given n and two arrays A[] and B[], A and B have size of n-1, and there exists an edge between A[i] and B[i].

Example:
Input: n = 3, A[] = {1, 1, 1}, B[] = {2, 3, 4}
Output: 2

*/

class Solution{
public:

    int minDiffInBST(int& n, vector<int>& a, vector<int>& b) {
        int minDiff = INT_MAX;
        vector<vector<int>> adj(n+1);
        vector<int> sum(n+1, 0);
        for(int i=0; i<a.size(); i++){
            adj[a[i]].emplace_back(b[i]);
            adj[b[i]].emplace_back(a[i]);
        }
        int total = (n*(n+1))/2;
        dfs(1, -1, total, adj, sum, minDiff);
        for(auto& i : sum){
            cout<<i<<" ";
        }
        cout<<endl;
        return minDiff;
    }

    int dfs(int i, int parent, int& total, vector<vector<int>>& adj, vector<int>& sum, int& ans){
        sum[i] = i;
        for(auto& next : adj[i]){
            if(next!=parent){
                sum[i] += dfs(next, i, total, adj, sum, ans);
                ans = min(ans, abs(total - 2*sum[next]));

            }
        }
        return sum[i];
    }

};

int main(){

    int n = 3;
    //int a[] = {1,1,1};
    //int b[] = {2,3,4};
    vector<int> a = {1,1};
    vector<int> b = {2,3};
    Solution s;
    cout<<s.minDiffInBST(n, a, b)<<endl;
    return 0;
}