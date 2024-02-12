#include <iostream>
#include <vector>
using namespace std;

/*
Description:
You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].
->The number of global inversions is the number of the different pairs (i, j) where:
0 <= i < j < n
nums[i] > nums[j]

->The number of local inversions is the number of indices i where:
0 <= i < n - 1
nums[i] > nums[i + 1]

Return true if the number of global inversions is equal to the number of local inversions.
*/

class Solution {
public:

    long long merge(vector<int>& n, int start, int mid, int end) {
        long long count = 0;
        int size1 = mid - start + 1, size2 = end - mid;
        int* ll = new int[size1];
        int* rr = new int[size2];
        for (int i = 0; i < size1; i++) {
            ll[i] = n[start + i];
        }
        for (int i = 0; i < size2; i++) {
            rr[i] = n[mid + 1 + i];
        }
        int index1 = 0, index2 = 0, arrayIndex = start;
        while (index1 < size1 && index2 < size2) {
            if (ll[index1] <= rr[index2]) {
                n[arrayIndex++] = ll[index1++];
            } else {
                count += size1 - index1;
                n[arrayIndex++] = rr[index2++];
            }
        }
        while (index1 < size1) {
            n[arrayIndex++] = ll[index1++];
        }
        while (index2 < size2) {
            n[arrayIndex++] = rr[index2++];
        }

        delete[] ll;
        delete[] rr;
        return count;
    }

    long long mergeSort(vector<int>& n, int start, int end) {
        long long count = 0;
        if (start >= end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        count += mergeSort(n, start, mid);
        count += mergeSort(n, mid + 1, end);
        count += merge(n, start, mid, end);
        return count;
    }

    int getLocal(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }
        return count;
    }

    bool isIdealPermutation(vector<int>& nums) {

        for(int i=0; i<nums.size();i++){
            if(abs(nums[i]-i)>1){
                return false;
            }
        }
        return true;
        /*//Hefty solution
        //Keeping it above as mergesort will update the nums, and so this will return 0
        int local = getLocal(nums);
        long long global = mergeSort(nums, 0, nums.size() - 1);
        return global == local;
        */
    }
};