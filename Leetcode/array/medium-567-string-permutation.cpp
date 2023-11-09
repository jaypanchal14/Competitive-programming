#include<iostream>
#include<string>

using namespace std;

/*
Objective :
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Case:
1)
Input : s1 = ab, s2 = eidbaoaoo
Output : true
2)
Input : s1 = ab, s2 = eidbwaoaoo
Output : false
*/

bool checkInclusion(string s1, string s2) {
    int a1[26] = {0};
    int a2[26] = {0};
    int size1 = s1.size();
    int size2 = s2.size();
    if(size1>size2){
        return false;
    }
    for(int i=0; i<size1;i++){
        a1[s1[i]-'a']++;
        a2[s2[i]-'a']++;
    }
    
    for(int start=0; start<=size2-size1;start++){
        int end = start+size1;
        if(end != size1){
            a2[s2[start-1]-'a']--;
            a2[s2[end-1]-'a']++;
        }

        bool isEqual = true;
        for(int i=0; i<26;i++){
            if(a1[i]!=a2[i]){
                isEqual = false;
                break;
            }
        }
        if(isEqual){
            return true;
        }
    }
    return false;
}

int main(){
    string s1;
    cout<<"Enter first string: ";
    getline(cin, s1);
    string s2;
    cout<<"Enter second string: ";
    getline(cin, s2);
    bool isfound = checkInclusion(s1,s2);
    cout<<"Is first string's permutation present in second: "<<isfound<<endl;
    return 0;
}