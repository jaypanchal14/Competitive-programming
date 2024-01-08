#include<iostream>
#include<map>
using namespace std;

int main(){
    string s = "anagraa";
    string t = "naagram";

    if(s.length() != t.length()){
        cout<<"Not anagram";
        return 0;
    }

    map<char, int> mp;
    for(char c : s){
        if(mp.find(c)!=mp.end()){
            mp[c] = mp[c]+1;
        }else{
            mp[c] = 1;
        }
    }
    int a = 1;
    for(char c : t){
        if(mp.find(c)!=mp.end()){
            mp[c] = mp[c]-1;
            if(mp[c] == 0){
                mp.erase(c);
            }
        }else{
            a = 0;
            break;
        }
    }
    if (a==1)
    {
        cout<<"Is Anagram";

    }else{
        cout<<"Not anagram";
    }
    
    return 0;
}