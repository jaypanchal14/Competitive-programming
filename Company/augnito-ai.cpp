#include<iostream>

using namespace std;

/*
Que : 1 -> Climb jump question : 
given N, you can either take 1 step or 2 steps at a time.
Return total number of different ways to reach given target int.

Que : 2 -> String challenge
Given string str, consisting of alphabets, '+' and '='. 
Constraint is : Each letter should be surrounded by the '+'.
Return true or false if it follows contraint.

Que : 3 -> Searching challenge
Given two numbers, num1 and num2, if there are continours triple occurrence of some digit in num1 and 
double occurrence of some digit in num2, then return 1, otherwise return 0;

Que : 4 -> Largest area of rectangle with all '1' in given matrix of binary character.

Que : 5 -> String challenge
Given string of words, find the first word with the greatest number of repeated letters. (Non-continuous character is fine)
Example : "Hello apple pie" -> "Hello" (with two occurrence of l in hello)

Que : 6 -> Smallest substring of str1 containing all the characters of the second string str2
leetcode-76

Que : 7 -> Gas station
Que : 8 -> Nth prime number

*/

bool isValidString(string& str) {
    if (str.empty()) {
        return false; // An empty string is not valid
    }

    size_t size = str.size();

    // Check the first character
    if (isalpha(str[0]) || isalpha(str[size - 1])) {
        return false;
    }

    // Check for letters surrounded by '+'
    for (size_t i = 1; i < str.length() - 1; ++i) {
        if (isalpha(str[i])) {
            // If the character is a letter, check its surrounding characters
            if (str[i - 1] != '+' || str[i + 1] != '+') {
                return false;
            }
        }
    }

    return true;
}