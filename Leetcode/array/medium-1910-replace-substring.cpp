#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

string removeOccurrences(string s, string part){
    size_t index = s.find(part);
    int sz = part.size();
    while(index != string::npos){
        //s.replace(index, sz, "");

        //To delete <sz> number of characters starting from index <index>
        s.erase(index, sz);
        index = s.find(part);
    }

    return s;
}

int main(){
    string first,output;
    cout<<"Enter yout string: ";
    getline(cin, first);

    string replacement;
    cout<<"Enter yout string which you want to replace: ";
    getline(cin, replacement);
    output = removeOccurrences(first, replacement);
    cout<<"Output after replacement is: "<<output;
    return 0;
}