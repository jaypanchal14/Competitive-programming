#include<iostream>
#include<vector>

using namespace std;

/*
Que : 1
Given an integer N, find number of pairs between i and j, (1<=i,j<=N)
count pairs of i and j having as i*j as a perfect square number.

Que : 2
Given an array of integer with below value and meaning, find maximum number of days the shop-owner sells items from the same stock.
a)if shop[i] == 1 :
    stock refreshed, no selling on this day
b)if shop[i] == 0 :
    open for selling
c)if shop[i] ==-1 :
    shopkeeper returns the stock, no selling

Que : 3 (Segment tree or BIT based)
You are a manager in the office, and you keep track of all the employees with the help of an array.
Array is of 2*N size, 
where N indicated the number of employee with id from 1 to N (first column), and their respective salary(second column).
You are given an array of query, each having three elements: l(start-id), r(end-id), limit :
for each query, you need to return the count of employees having salary greater than limit.
*/

//Que : 2
int countDays(vector<int>& shop){
    int ans = 0, cur = 0;
    bool hasStock = false;
    for(int& s : shop){
        if(s==1){
            hasStock = true;
            cur = 0;
        }else if(s==0){
            if(hasStock){
                cur++;
            }
        }else{
            hasStock = false;
            cur = 0;
        }
        ans = max(ans, cur);
    }
    return ans;
}