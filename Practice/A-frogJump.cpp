#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {30,10,60,10,60,50};

    int n = v.size();
    vector<int> ans(n,0);

    ans[0] = 0;

    ans[1] = abs(v[0]-v[1]);
    for(int i = 2; i<n; i++){
        ans[i] = min(ans[i-2] + abs(v[i]-v[i-2]), ans[i-1] + abs(v[i]-v[i-1]));
    }
    cout<<"Answer is:"<<ans[n-1]<<endl;
    return 0;
}