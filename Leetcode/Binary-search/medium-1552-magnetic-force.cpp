#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. 
Rick has n empty baskets, the ith basket is at position[i], 
Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.
Example:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
*/

class Solution {
public:

    /*
    Logic : Get the least and highest force between two balls, and find greedily using binary search.
    */
    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(), positions.end());
        int size = positions.size();
        int ans = 0;
        int l = 0, r = positions[size-1]-positions[0];
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(check(positions, mid, m)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }

    bool check(vector<int>& p, int mid, int m){
        int count = 1, start = 0;
        for(int i=1; i<p.size(); i++){
            if(p[i]-p[start]>=mid){
                count++;
                start = i;
                if(count==m){
                    break;
                }
            }
        }
        return count==m;
    }

};