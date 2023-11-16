#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;

int main(){

    vector<int> v = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int k = 4;
    int n = v.size();
    vector<int> ans(n,INT_MAX);

    ans[0] = 0;

    ans[1] = abs(v[0]-v[1]);
    for(int i = 1; i<n; i++){
        for(int j = 1; j <= k; j++) if(i-j>=0){
            ans[i] = min(ans[i] , ans[i-j] + abs(v[i]-v[i-j]));
        }
    }
    cout<<"Answer is:"<<ans[n-1]<<endl;
    return 0;
}