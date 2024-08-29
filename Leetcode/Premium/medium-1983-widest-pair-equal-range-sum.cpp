#include<vector>
#include<unordered_map>

using namespace std;

/*
Description:
You are given two 0-indexed binary arrays nums1 and nums2. Find the widest pair of indices (i, j) such that 
i <= j and nums1[i] + nums1[i+1] + ... + nums1[j] == nums2[i] + nums2[i+1] + ... + nums2[j].
The widest pair of indices is the pair with the largest distance between i and j. 
The distance between a pair of indices is defined as j - i + 1.
Return the distance of the widest pair of indices. If no pair of indices meets the conditions, return 0.

Example:
Input: nums1 = [1,1,0,1], nums2 = [0,1,1,0]
Output: 3
*/

class Solution {
public:

    /*
    Logic:
    From line-10, we can say
    nums1[i] + nums1[i+1] + ... + nums1[j] - (nums2[i] + nums2[i+1] + ... + nums2[j]) = 0
    which is equal to
    (nums1[i] - nums2[i]) + (nums1[i+1] - nums2[i+1]) + ... + (nums1[j] - nums2[j]) = 0
    Then we are just using prefix with unordered_map to find the widest gap
    */
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> d;
        d[0] = -1;
        int ans = 0, s = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            s += nums1[i] - nums2[i];
            if (d.count(s)) {
                ans = max(ans, i - d[s]);
            } else {
                d[s] = i;
            }
        }
        return ans;
    }
};