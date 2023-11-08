#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    char name[30];
    cin>>name;
    cout<<"Entered name is: "<<(char)toupper(name[0])<<endl;

    cout<<"Magic: "<<(char)(name[1] - 'a' + 'A')<<endl;
    
    string a = "asdasf";
    cout<<a.length()<<" "<<a[0];

    return 0;
}