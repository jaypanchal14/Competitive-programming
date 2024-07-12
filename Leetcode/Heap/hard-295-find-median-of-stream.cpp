#include<queue>
#include<iostream>

using namespace std;

/*
Description:
The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Example:
Input ->
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output -> [null, null, null, 1.5, null, 2.0]
*/

class MedianFinder {
public:

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    int n;
    
    MedianFinder() {
        n = 0;
    }
    
    //After insertion, we are making sure that the size difference between the maxi and mini heap is
    // not larger than 1.
    void addNum(int num) {
        if(maxi.size() && maxi.top() < num){
            mini.push(num);
        }else{
            maxi.push(num);
        }
        if(mini.size() > maxi.size() + 1){
            maxi.push(mini.top());
            mini.pop();
        }
        if(maxi.size() > mini.size() + 1){
            mini.push(maxi.top());
            maxi.pop();
        }
        
        n++;
    }
    
    double findMedian() {
        if(n & 1){
            if(maxi.size() > mini.size()){
                return maxi.top();
            }else{
                return mini.top();
            }
        }else{
            return ((double)maxi.top() + mini.top())/(double)2;
        }
    }
};