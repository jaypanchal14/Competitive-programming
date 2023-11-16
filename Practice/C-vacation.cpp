#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){

    int a=0, b=0, c=0;

    vector<vector<int>> v{{10, 40, 70},{20, 50, 80},{30, 60, 90}};
    vector<int> ans(3, INT_MIN);
    int n = v.size();
    ans[0] = v[0][0];
    ans[1] = v[0][1];
    ans[2] = v[0][2];
    int k,l,m;
    for(int i=1; i<n; i++){
        a = v[i][0];
        b = v[i][1];
        c = v[i][2];
        k = a + max(ans[1],ans[2]);
        l = b + max(ans[0],ans[2]);
        m = c + max(ans[0],ans[1]);
        ans[0] = k;
        ans[1] = l;
        ans[2] = m;
    }
    cout<<"Maximum happiness is: "<< *max_element(ans.begin(), ans.end());
    return 0;
    
}