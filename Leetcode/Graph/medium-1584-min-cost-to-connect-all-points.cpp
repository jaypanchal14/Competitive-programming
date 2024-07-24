#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Description:
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.
Example:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
*/

using pp = pair<int,int>;
class Solution {
public:

    //Approach is based on prim's algorithm
    //Include one node which is not already visited and having least distance from the MST.
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size(), index;
        if(n==1){
            return 0;
        }
        vector<bool> visited(n, false);
        long ans = 0, dd, mini;
        int count = n;
        //first is distance, second is index
        //If you want to store which points we included in the MST, you can take
        // pp as pair<int, pair<int, int>> where we would store index of both the nodes of that particular edge
        priority_queue<pp, vector<pp>, greater<pp>> q;
        q.push({0,0});
        pp tmp;
        while(!q.empty() && count>0){
            tmp = q.top();
            q.pop();
            index = tmp.second;
            if(visited[index]){
                continue;
            }
            count--;
            ans += tmp.first;
            visited[index] = true;
            for(int i=0; i<n; i++){
                if(!visited[i]) {
                    // Calculate Manhattan distance
                    dd = abs(p[index][0] - p[i][0]) + abs(p[index][1] - p[i][1]);
                    q.push({dd, i});
                }
            }
        }
        return ans;
    }
};