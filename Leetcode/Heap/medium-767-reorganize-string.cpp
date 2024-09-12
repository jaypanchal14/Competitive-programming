#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Description:
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example:
Input: s = "aab"
Output: "aba"
*/

class compare{
public:
    //This gives us the max heap
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

class Solution {
public:

    string reorganizeStringQueueOptimized(string s){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> q;
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(v[i]){
                q.push(make_pair(i, v[i]));
            }
        }
        if(q.top().second > (s.size()+1)/2){
            return "";
        }
        pair<int,int> tmp;
        int index = 0;
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            while(index < s.size() && tmp.second>0){
                s[index] = 'a'+tmp.first;
                index = index+2;
                tmp.second--;
            }
            if(index >= s.size()){
                index = 1;
            }
            while(index < s.size() && tmp.second>0){
                s[index] = tmp.first+'a';
                index = index+2;
                tmp.second--;

            }

        }
        return s;

    }

    string reorganizeStringWithQueue(string s) {
        string ans = "";
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> q;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, compare> second;
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(v[i]){
                q.push(make_pair(i, v[i]));
            }
        }
        pair<int,int> tmp, second;
        second = {-1,-1};
        int count = s.size();
        
        while(count--){
            if(q.size()){
                tmp = q.top();
                q.pop();
                if(second.first == -1){
                    if(ans.size() && ans.back()==(tmp.first+'a')){
                        return "";
                    }
                    ans.push_back(tmp.first+'a');
                    tmp.second--;
                    if(tmp.second>0){
                        second = tmp;
                    }
                }else{
                    if(ans.size() && ans.back()==(tmp.first+'a')){
                        return "";
                    }
                    ans.push_back(tmp.first+'a');
                    tmp.second--;
                    q.push(second);
                    if(tmp.second>0){
                        second = tmp;
                    }else{
                        second = {-1,-1};
                    }    
                }
                
            }else{
                if(ans.back() == second.first+'a'){
                    return "";
                }
            }
        }
        return ans;
    }
};