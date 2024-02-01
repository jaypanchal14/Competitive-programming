#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

/*
Description : 
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Input: arr = ["un","iq","ue"]
Output: 4

*/

class Solution {
public:

    int size;
    vector<string> m;
    int get(string s, int i){
        int result = s.size();
        if(i>=size){
            return result;
        }
        vector<int> v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        bool present = false;
        for(char c:m[i]){
            if(v[c-'a']>0){
                present = true;
                break;
            }
        }
        if(i==size-1){
            if(present){
                return max(s.size(), m[size-1].size());
            }else{
                return s.size()+m[size-1].size();
            }
        }
        if(present){
            return get(s, i+1);
        }else{
            return max(get(s,i+1), get(s+m[i],i+1));
        }
    }

    int maxLength(vector<string>& arr) {
        size = arr.size();
        for(int i=0; i<size;i++){
            vector<int> v(26,0);
            for(char c:arr[i]){
                if(v[c-'a']>0){
                    arr[i] = "";
                    break;
                }else{
                    v[c-'a']++;
                }
            }
        }
        //pp(arr);
        if(size==1){
            return arr[0].size();
        }
        m = arr;
        return max(get("",1), get(arr[0],1));
    }

    void pp(vector<string> arr){
        for(string s:arr){
            for(char c:s){
                cout<<c;
            }
            cout<<endl;
        }
    }
};