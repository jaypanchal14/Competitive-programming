#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main(){

    /*char name[30];
    cout<<"Enter a name: ";
    cin>>name;
    cout<<"Entered name is: "<<(char)toupper(name[0])<<endl;

    cout<<"Magic: "<<(char)(name[1] - 'a' + 'A')<<endl;
    
    string a = "asdasf";
    cout<<a.length()<<" "<<a[0]<<endl;

    //Adding this here, because while entering the name at "cin>>name;", 
    //the trailing '\n' would still remain in the cin.
    cin.ignore();
    
    char buf[30];
    cout<<"Enter a string of size <=30 : ";
    cin.getline(buf, 30);

    stringstream ss(buf);
    string pp;

    cout<<"Printing each word in different line: "<<endl;
    while(getline(ss, pp, ' ')){
        cout<<pp<<endl;
    }
    
    string i;
    cout<<"Enter a string: ";
    //By default, the delimeter is new-line '\n'
    getline(cin, i);
    //getline(cin, i, '!');
    //cout<<"String with delimeted '!' : "<<i;
    cout<<"String entered is : "<<i<<endl;
    cout<<"Is last two string equal: "<<strcmp(buf,i.c_str())<<endl;
    */
    char first[20] = "first";
    char dest[20];
    strcpy(dest, first);
    cout<<dest;

    return 0;
}