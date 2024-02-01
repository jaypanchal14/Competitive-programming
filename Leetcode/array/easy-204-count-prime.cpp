#include <iostream>
#include <vector>

using namespace std;

/*
Description : Given an integer n, return the number of prime numbers that are strictly less than n.
*/

int count(int n){
    vector<int> v(n+1,1);
    int ans = 0;
    v[0] = 0;
    v[1] = 0;
    for(int i=2; i<n;i++){
        if(v[i]){
            ans++;
            for(int j=2*i; j<n; j=j+i){
                v[j] = 0;
            }
        }
    }
    return ans;
}

int main(){

    cout<<"Number of primes before 20 is: "<<count(20)<<endl;
    return 0;
}