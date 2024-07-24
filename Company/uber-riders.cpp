#include<iostream>
#include<vector>

using namespace std;
/*
Description:
Given an array of users of size n, each element represents the strength of the respective user.
We need to define equal number of riders and drivers, such that no two drivers or riders are there in the index-vise order.
Rider should have the maximum possible strength.
Return an array representing each user as either R for rider or D for driver, otherwise "-1";
*/

string getAns(vector<int>& v){
    if(v.size() & 1){
        return "-1";
    }
    int a = 0, b = 0;
    for(int i=0; i<v.size(); i++){
        if(i & 1){
            a += v[i];
        }
        else{
            b += v[i];
        }
    }
    string ans = "";
    if(a > b){
        for(int i=0; i<v.size()/2; i++){
            ans.append("RD");
        }
    }else{
        for(int i=0; i<v.size()/2; i++){
            ans.append("DR");
        }
    }
    return ans;
}

int main(){
    vector<int> v = {10,20,25,20,31,20,15,20};
    cout<<""<<getAns(v)<<endl;
    return 0;
}