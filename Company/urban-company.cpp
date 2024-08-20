/*

1) Binary search problem
We have one array of integer arr, an integer M, and an array of mapping of same size as arr.
At first day, i can fill first house at index present on the first index of mapping, on second day, 
i would feel house at val present on index 2 of mapping, etc etc..
Find how many days you need so that we can get "M" consecutive house.

2) Trie problem
I have an array of integer sequence, of size M. Each special sequence contains integer, we can ignore the trailing -1.
It can have 0 or more trailing zeroes, which we need to ignore.
Then we have an array of queries, each is of same size and follows same pattern as special sequence.
For all given query sequences, find how many special sequence have the same prefix.

3) Consecutive crayon colour score, DP
You are given a box of crayons with different colours represented by different alphabets. 
In one operation, you can remove several continuous crayons of the same colour. 
You may perform this operation several times until the box is empty. Each time you can choose the crayon set. 
They must be continuous and of the same colours (i.e., set of x crayons, x>=1). 
After removing them, you will get x*x points.
Input:
You are given an integer N where N denotes the total number of crayons in the box. 
You are also given an array of colours denoting the N colours in the box, 
where each colour is represented by an English alphabet. (1≤N≤60)
Output:
Return the maximum points, you can get in the given scenario.

https://thejoboverflow.com/p/p863/
or
https://leetcode.com/problems/remove-boxes/

*/