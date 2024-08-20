#include<vector>
#include<iostream>
#include<climits>
using namespace std;

/*
Description:
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. 
You are also given an integer shelfWidth.
We want to place these books in order onto bookcase shelves that have a total width shelfWidth.
We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, 
then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. 
We repeat this process until there are no more books to place.
Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.
For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, 
the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

Example:
Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
*/


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        dp[n-1] = books[n-1][1];
        int h,w;
        for(int i=n-2; i>=0; i--){
            h = books[i][1];
            w = books[i][0];
            dp[i] = h+dp[i+1];
            for(int j=i+1; j<n;j++){
                w += books[j][0];
                if(w<=shelfWidth){
                    h = max(h, books[j][1]);
                    dp[i] = min(dp[i], h+dp[j+1]);
                }else{
                    break;
                }
            }
        }

        return dp[0];
        //Memoization 1D
        //vector<int> dp(n, -1);
        //return rec(0, books, shelfWidth, dp);
        
        //Memoization 2D
        //Here, you can take shelfWidth instead of 1001 as well. 
        //I have taken 1001 as it was maximum possible shelfWidth value from the constraint.
        //vector<vector<int>> dp(n,vector<int>(1001,-1));
        // return getMemo(0, 0, 0, books, shelfWidth, dp);
    }

    int rec(int index, vector<vector<int>>& books, int& width, vector<int>& dp){
        if(index==books.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int h = 0, w = 0, x;
        int ans = INT_MAX;
        for(int i=index; i<books.size(); i++){
            w += books[i][0];
            if(w<=width){
                h = max(h, books[i][1]);
                ans = min(ans, h + rec(i+1, books, width, dp));
            }else{
                break;
            }
        }
        return dp[index] = ans;
    }

    int getMemo(int i,int curW, int h, vector<vector<int>>& books, int& width,
                vector<vector<int>>& dp
    ){
        if(i==books.size()){
            return h;
        }
        if(dp[i][curW]!=-1){
            return dp[i][curW];
        }
        int exclude = h + getMemo(i+1, books[i][0], books[i][1], books, width, dp);;
        int include = 1e9;
        if(curW+books[i][0]<=width){
            h = max(h, books[i][1]);
            include = getMemo(i+1, curW+books[i][0], h, books, width, dp);
        }
        return dp[i][curW] = min(include, exclude);
    }
};