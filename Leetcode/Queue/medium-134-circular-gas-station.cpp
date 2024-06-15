#include<vector>

using namespace std;

/*
Description :
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around 
the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.

Example :
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
*/

class Solution {
public:
    /*
    Here, we are calculating current petrol and deficiency at each station.
    T.C : O(N)
    */
    int canCompleteCircuitWithPrefixLogic(vector<int>& gas, vector<int>& cost) {
        int ans = 0, sum = 0, deficit = 0;
        for(int i=0 ;i<gas.size(); i++){
            sum += gas[i]-cost[i];
            if(sum<0){
                deficit += sum;
                sum = 0;
                //Because, we can't react ith station from any station between ans and (i-1)th,
                //as there would always be deficiency of petrol in-between 
                ans = i+1;
            }
        }
        return (sum+deficit>=0) ? ans : -1;
    }

    // T.C : O(2N)
    int canCompleteCircuitWithQueueLogic(vector<int>& gas, vector<int>& cost) {
        int ans = -1;
        int size = gas.size();
        int p = 0;
        for(int i=0; i<gas.size(); i++){
            p += gas[i]-cost[i];
        }
        if(p<0){
            return -1;
        }
        p = 0;
        int front = 0, rear = 0, start;
        while(rear<size){
            p += gas[rear]-cost[rear];
            if(p<0){
                p = 0;
                front = rear+1;
                rear = front;
            }else{
                rear++;
            }

        }
        return front;
    }
};