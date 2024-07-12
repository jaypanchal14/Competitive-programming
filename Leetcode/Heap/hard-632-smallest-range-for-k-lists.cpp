#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

class Node{
public:
    int val, row, col;
    Node(int v, int r, int c){
        val = v;
        row = r;
        col = c;
    }
};

class compare{
public:
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }

};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int maxi = INT_MIN;
        // In case we want to use class Node for representing our item
        // priority_queue<Node*, vector<Node*>, compare> q;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        for(int i=0; i<k; i++){
            maxi = max(maxi, nums[i][0]);
            // q.push(new Node(nums[i][0], i, 0));
            q.push({nums[i][0], {i, 0}});
        }
        pair<int,pair<int,int>> tmp;
        // int mini = q.top()->val;
        int mini = q.top().first;
        int start = mini, end = maxi;
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            // mini = tmp->val;
            mini = tmp.first;
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            // if(tmp->col < nums[tmp->row].size()-1){
            if(tmp.second.second < nums[tmp.second.first].size()-1){
                // cout<<tmp->row<<" - "<<tmp->col<<endl;
                maxi = max(maxi, nums[tmp.second.first][tmp.second.second + 1]);
                q.push({nums[tmp.second.first][tmp.second.second + 1], {tmp.second.first, tmp.second.second + 1}});
                // q.push(new Node(nums[tmp->row][tmp->col + 1], tmp->row, tmp->col + 1));
            }else{
                break;
            }

        }
        return {start, end};
    }
};