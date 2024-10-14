/*
Que : 1
We define good string with two constraint
1) Equal number of 1s and 0s.
2) All the prefix should contain no less number of 1s than 0s.
Example : '110100'
For given binary string, there can be multiple good substring.
If two consecutive substring are good, they can be swapped only if after swapping it remains good string.
given a good binary string, perform zero or more swap operations on its adjacent good substrings such that the resulting string is the largest
possible numeric value. Return the same string after swapping.

Logic:
Get the first good substring [start, i] and store it in separate vector of string with value of largest possible number between (start, i) exclusively.
Similarly find all such number and, sort it in descending.


Que : 2 (In C language)
Given n as input,  n => number of total test-cases
Followed by total n different binary string consisting of '1' and '0'.

Write a  function which will process above input and for each string print either True or False,
if the decimal value converted from the binary string is power of 2 or not, respectively.

Logic : Count the ones.
if ones == 1 -> Print True
else Print -> Print False
*/