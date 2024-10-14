#include<iostream>

using namespace std;

//1)Macro : Which will be replaced with the symbol before compiling
#define MAC 'a'
#define fun(a,b)(a+b)
static int x = 10;

//2)Global variable : It is generally bad practice to use global variable in the program
int globalV = 'r';

//3)Inline function : Will be replaced before the compilation
inline int getSum(int a, int b){
    return a+b;
}

int main(){
    
    // cout<<MAC<<", Function from macro:"<<fun(1,2)<<endl;
    // cout<<"Global:"<<globalV<<endl;
    // cout<<getSum(12,23)<<endl;
    
    /*int a = 264;
    int* b = &a;
    cout<<"Address of a:"<<b<<endl;
    cout<<"Value of a:"<<*b<<endl;

    char* c = (char*)(b);
    cout<<"Address of a:"<<(void*)c<<endl; //Same address as b
    cout<<"Value of a:"<<(int)*c<<endl; //prints 8
    */

    static int u = 10;
    int x = 1;
    {
        x += u || x - 1 && (x==2);
    }
    cout<<x; //Will consider nearest variable definition
    return 0;
}