#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Description:
A flight can freely visit any open country but are not allowed to land in or fly from the restricted countries.
However, uber can obtain special government permissions to convert some R countries to O status. 
Due to a hardware malfunction in the permission issuing machine, it can only generate the requested permissions in pairs(2 at a time). 
Requesting more permissions than the no. of R countries is illegal and will result in error.
For each country, determine the maximum number of countries that can be visited by flight originating from that country, assuming optimal
conversion of R to O countries. We can visit a country only if it is O. Each country obtains the special permissions independently from other countries.
So, the special permissions for flight from one country are independent of the permissions for flights from the other country.
If the home country is R, them you do not get permissions for the home country, then all the flights will not be allowed to take off from the country.

Input:
First line contains n, the total number of countries.
Second line contains a string of size n, consisting of only O and R characters.
Third line contains an array of integers of length n-1, indicating the flight root of the counties.
ith element of the array (considering the 1-indexed array) denotes the country number with which the flight from i+1th country connects bidirectionally.

Output:
Return the sum of elements of an array of n integers, the ith of which is the max no. of countries visitable by flight starting from the ith country.
Constraints:
1<=n<=10^5
1<=flight root<=n

Example:
Input:
7
ROROROO
1 1 3 3 5 5

Output:
33
[4 4 5 5 5 5 5] sum = 33

*/
