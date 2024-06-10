#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
Description:
Given a N*N matrix, where v[i][j] indicates ith person knows jth person. Return the celebrity if exists.
Celebrity is who, knows no-one and everyone knows him.
*/

int getCelebrityUsingStack(vector<vector<int>>& v){
    int candidate = 0;
    stack<int> s;
    for(int i=0; i<v.size(); i++){
        s.push(i);
    }
    int a, b;
    while(s.size()>1){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        if(v[a][b]){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    a = 0;
    b = 0;
    candidate = s.top();
    for(int i=0; i<v.size(); i++){
        //count row
        if(v[candidate][i]==1){
            a++;
        }

        //count column
        if(v[i][candidate]==1){
            b++;
        }        
    }
    if(b == v.size()-1 && a==0){
        return candidate;
    }
    return -1;
}

int getCelebrity(vector<vector<int>>& v){
    int candidate = 0;
    for(int i=1; i<v.size(); i++){
        if(v[candidate][i]==1){
            candidate = i;
        }
    }
    for(int i=0; i<v.size(); i++){
        if(i==candidate)    continue;

        if(v[candidate][i]==1 || v[i][candidate]==0){
            return -1;
        }
    }
    return candidate;
}

int main(){
    vector<vector<int>> v = { { 0, 0, 1, 0 },
                    { 0, 0, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 1, 0 } };
    // int ans = getCelebrity(v);
    int ans = getCelebrityUsingStack(v);
    if(ans==-1){
        cout<<"No celebrity"<<endl;
    }else{
        cout<<"Celebrity found: "<<ans<<endl;
    }
    return 0;
}