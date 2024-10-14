#include<vector>
#include<iostream>

using namespace std;

/*
Logic :
1) Based on the needle, generate the LPS array. (Longest prefix suffix).
lps[i] = max of {needle[0:k-1] == needle[i-k+1 : i] } for k belongs to [0,i]
It indicated, with which index it needs to match for the next iteration
2) Start iterating over the haystack and keep track of i and j over h and n respectively.
3.1) If h[i] == n[j], then increment both i and j.
3.2) Else
        If j is not zero, then update j to lps[j-1] and continue
        Else j is zero, then increment i and continue.
4) While traversing, if j==needle.size(), then return index = (i-needle+1);

Example:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
*/

vector<int> getLPS(string& n){
    int size = n.size();
    vector<int> lps(size, 0);
    int p = 0, i = 1;
    while(i<size){
        if(n[i]==n[p]){
            lps[i] = ++p;
            i++;
        }else if(p==0){
            lps[i++] = 0;
        }else{
            p = lps[p-1];
        }
    }
    return lps;
}

int findInHaystack(string h, string n){
    vector<int> lps = getLPS(n);
    int i = 0, j = 0;
    while(i<h.size()){
        if(h[i]==n[j]){
            i++;
            j++;
        }else if(j==0){
            i++;
        }else{
            j = lps[j-1];
        }
        if(j==n.size()){
            return i-j+1;
        }
    }
    return -1;
}

int main(){
    string haystack = "hello";
    string needle = "ll";
    int index = -1;
    index = findInHaystack(haystack, needle);
    if(index != -1){
        cout<<"found in the haystack at index: "<<index<<endl;

    }else{
        cout<<"Not found in the haystack. \n";
    }
    return 0;
}