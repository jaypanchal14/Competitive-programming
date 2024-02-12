#include<iostream>
#include<vector>

using namespace std;

void get(int size, string tmp,int current, vector<string>& ans, vector<int> v){
    //cout<<"tmp:"<<tmp<<", current:"<<current<<endl;
    if(current >= size){
        ans.push_back(tmp);
        return;
    }
    for(int i=0; i<26; i++){
        if(v[i]){
            tmp.push_back('a'+i);
            v[i]--;
            get(size, tmp, current+1, ans, v);
            v[i]++;
            tmp.pop_back();
        }
    }
}

int main(){
    string s = "abc";
    vector<string> ans;
    vector<int> v(26,0);
    for(char c: s){
        v[c-'a']++;
    }
    get(s.size(), "", 0, ans, v);
    for(string item : ans){
        cout<<item<<", ";
    }
    return 0;
}