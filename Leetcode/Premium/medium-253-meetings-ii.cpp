#include<vector>
#include<queue>
using namespace std;

/*
Description:
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

Example:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
*/

class compare{
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.first==b.first){
            a.second > b.first;
        }
        return a.first < b.first;
    }
};

class Solution{
public:
    int getRooms(vector<vector<int>>& meetings){
        int ans = 0, cur = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        for(auto& m : meetings){
            q.push({m[0], 1});
            q.push({m[1], 0});
        }
        pair<int, int> tmp;
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            if(tmp.second == 1){
                cur++;
                ans = max(ans, cur);
            }else{
                cur--;
            }
        }
        return ans;
    }

};