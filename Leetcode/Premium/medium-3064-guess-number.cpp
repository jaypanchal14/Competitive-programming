#include<iostream>
using namespace std;

/*
Description : 
You have given a number, you need to write method definition for findNumber method for finding pre-defined number 
with the help of commonSetBits method.

Input : NULL
Output : pre-defined int
*/

class Solution {
public:
    
    int NUM = 98331;
    
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i)) {
                n |= 1 << i;
            }
        }
        return n;
    }

    int commonSetBits(int num){
        int count = 0;
        int tmp = NUM;
        while(num>0){
            if((tmp & 1) && (num & 1)){
                count++;
            }
            tmp = tmp >> 1;
            num = num >> 1;
        }
        return count;
    }
};

int main(){
    // cout<<"Input a numner:";
    Solution s;
    // cin>>s.NUM;
    cout<<"My guess: "<<s.findNumber()<<endl;
    return 0;
}

