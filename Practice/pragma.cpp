#include<iostream>

using namespace std;

//Pragma are compiler directions provided by user

//Below will stop the program compilation and give error when it will encouter usage of poisoned variable
//here, it is cout
// #pragma GCC poison cout

int main(){
    cout<<"Print\n";
    return 0;
}