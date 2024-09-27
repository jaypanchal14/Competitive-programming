#include<string>
using namespace std;

/*
Description:
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
*/
class Solution {
public:


    //Logic : Check for normal, if inequality found, check for the remaining substring
    //1) after deleting one char from left : [i+1, j]
    //2) after deleting one char from right: [i, j-1]
    bool validPalindrome(string& s) {
        bool flag = true;
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if(flag){
            return true;
        }
        return (check(s, i, j-1) || check(s, i+1, j));
    }

    bool check(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};