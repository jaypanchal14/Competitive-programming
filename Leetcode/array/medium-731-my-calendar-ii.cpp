#include<vector>
#include<map>

using namespace std;

/*
Description:
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events).
The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), 
the range of real numbers x such that start <= x < end.

Example:
Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]
*/

using pp = pair<int, int>;
class MyCalendarTwo {
public:

    map<int, int> m;
    vector<pp> first, sec;

    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        int n = sec.size();
        //Check in overlapping intervals (already double booking)
        for(int i=0; i<n; i++){
            if((sec[i].first<=start && sec[i].second > start) || 
                (sec[i].first<end && sec[i].second >= end) || 
                (start < sec[i].first && end > sec[i].second)){
                return false;
            }
        }

        n = first.size();
        int l, r;
        //Otherwise, if no double booking
        for(int i=0; i<n; i++){
            l = max(start, first[i].first);
            r = min(end, first[i].second);
            if(l<r){
                //Get the double booking interval
                sec.emplace_back(l,r);
            }
        }
        first.emplace_back(start, end);
        return true;
    }
    
    bool bookWithSweepLineAlgo(int start, int end) {
        m[start]++;
        m[end]--;
        int count = 0;
        for(auto& p : m){
            count += p.second;
            if(count>2){
                m[start]--;
                m[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */