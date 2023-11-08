#include <iostream>
#include <vector>
using namespace std;

/*
Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
*/

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end){
        if (!isalnum(s[start])){
            start++;
            continue;
        } 
        else if (!isalnum(s[end])){
            end--;
            continue;
        }
        else{
            if (tolower(s[start++]) != tolower(s[end--])){
                return false;
            }
        }
    }
    return true;
}