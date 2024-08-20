#include<vector>
#include<algorithm>

using namespace std;

/*
Description:
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:

    /*
    Logic:
    Sort the envelopes based on the width. If two envelopes have the same width, sort them based on the height in descending order. 
    Then, check if the current envelop is bigger than previous
    - if yes, append its height
    - if not, check where can we put the height using lower_bound
    return the vector length
    */

    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), [](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n = e.size(), index;
        vector<int> h;
        h.emplace_back(e[0][1]);
        for(int i=1; i<n; i++){
            if(h.back() < e[i][1]){
                h.emplace_back(e[i][1]);
            }else{
                index = lower_bound(h.begin(), h.end(), e[i][1]) - h.begin();
                h[index] = e[i][1];
            }
        }

        return h.size();
    }
};