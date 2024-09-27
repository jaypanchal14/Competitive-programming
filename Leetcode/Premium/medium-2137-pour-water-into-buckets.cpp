#include<vector>
#include<algorithm>
using namespace std;

/*
Description:
You have n buckets each containing some gallons of water in it, represented by a 0-indexed integer array buckets, 
where the ith bucket contains buckets[i] gallons of water. You are also given an integer loss.
You want to make the amount of water in each bucket equal. 
You can pour any amount of water from one bucket to another bucket (not necessarily an integer).
However, every time you pour k gallons of water, you spill loss percent of k.
Example:
Input: buckets = [1,2,7], loss = 80
Output: 2.00000
Explanation: Pour 5 gallons of water from buckets[2] to buckets[0].
5 * 80% = 4 gallons are spilled and buckets[0] only receives 5 - 4 = 1 gallon of water.
All buckets have 2 gallons of water in them so return 2.
*/

class Solution {
public:

    double m;

    bool check(vector<int>& buckets, int& loss, int mid){
        double a = 0, b = 0;
        for(int& x : buckets){
            if(x < mid){
                b += mid-x;
            }else{
                a += m*(x-mid);
            }
        }
        return a>=b;
    }

    double equalizeWater(vector<int>& buckets, int loss) {
        double l = 0, mid, r = *max_element(buckets.begin(), buckets.end());
        m = (100-loss)*100;
        while(r - l > 1e-5){
            mid = l + (r-l)/2;
            if(check(buckets, loss, mid)){
                l = mid;
            }else{
                r = mid;

            }
        }
        return l;
    }
};