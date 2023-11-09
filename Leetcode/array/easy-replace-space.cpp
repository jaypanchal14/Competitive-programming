#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

/*
Objective :
To replace space with pre-defined group of characters ("@40" for this case)
*/

int main(){

    string s;
    string newDelimeter = "@40";
    string output = "";
    getline(cin, s);
    
    /* Using stringstream
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp, ' ')){
        output = output + tmp + newDelimeter;
    }
    output.pop_back();
    output.pop_back();
    output.pop_back();
    cout<<"new output is: "<<output<<endl;
    */

    //Using for loop
    /*for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            output = output + newDelimeter;
        }
        else{
            output.push_back(s[i]);
        }
    }
    cout<<"new output is: "<<output<<endl;
    */


    //Without using any extra space
    for(int i=0; i<s.size();){
        if(s[i]== ' '){
            s.replace(i, 1, newDelimeter);
            i += 3;
        }
        else{
            i++;            
        }
    }
    cout<<"new string is: "<<s<<endl;

    return 0;
}