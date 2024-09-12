#include<iostream>
#include<vector>

using namespace std;

/*
Description : Rotate matrix by 90 degree clockwise (in-place).
*/
void rotate(vector<vector<int>>& m) {
    int n = m.size();
    for(int j=0; j<n; j++){
        for(int i=0 ; i<n/2; i++){
            swap(m[i][j],m[n-i-1][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(m[i][j],m[j][i]);
        }    
    }
}

void print(vector<vector<int>> m){
    for(vector<int> v : m){
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main(){

    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(m);
    print(m);
    return 0;
}