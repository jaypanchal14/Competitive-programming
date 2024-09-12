#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

/*
Description:
You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
*/

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