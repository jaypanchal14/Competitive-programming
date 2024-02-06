#include<iostream>

using namespace std;

//1)Macro : Which will be replaced with the symbol before compiling
#define MAC 'a'
#define fun(a,b)(a+b)


//2)Global variable : It is generally bad practice to use global variable in the program
int globalV = 'r';

//3)Inline function : Will be replaced before the compilation
inline int getSum(int a, int b){
    return a+b;
}

int main(){
    
    cout<<MAC<<", Function from macro:"<<fun(1,2)<<endl;
    cout<<"Global:"<<globalV<<endl;
    cout<<getSum(12,23)<<endl;
    return 0;
}