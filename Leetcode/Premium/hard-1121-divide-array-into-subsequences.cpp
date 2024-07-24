#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
Description:
Given a non-decreasing array of positive integers nums and an integer K, 
find out if this array can be divided into one or more disjoint increasing subsequences of length at least K.
Example:
Input: nums = [1,2,2,3,3,4,4], K = 3
Output: true
*/

class Solution{
public:

    bool canDivideIntoSubsequences(vector<int>& v, int& k){
        //First approach
        int key = 0, count = 0;
        for(auto& ele : v){
            count = key == ele?count+1 : 1;
            if(count * k > v.size()){
                return false;
            }
            key = ele;
        }
        return true;
        //Second approach with linear space
        /*unordered_map<int, int> m;
        int maxi = 0, key;
        for(auto& val : v){
            m[val]++;
            if(m[val] > maxi){
                key = val;
                maxi = m[val];
            }
        }
        return maxi*k <= v.size();
        */
        //Third approach with N space
        /*
        vector<vector<int>> ans(maxi);
        int index = 0;
        for(auto& p : m){
            for(int i=p.second; i>0; i--){
                ans[index].emplace_back(p.first);
                index = (index+1)%maxi;
            }
        }
        for(auto& row : ans){
            for(int& el : row){
                cout<<el<<" ";
            }
            cout<<endl;
        }
        for(int i=0; i<maxi; i++){
            if(ans[i].size() < k){
                return false;
            }
        }
        return true;
        */
    }
};

int main(){
    Solution s;
    vector<int> v = {1,2,2,3,3,4,4};
    int k = 3;
    cout<<"Is possible:"<<s.canDivideIntoSubsequences(v, k);
    return 0;
}