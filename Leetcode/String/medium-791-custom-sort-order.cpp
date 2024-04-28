#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Description:
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Input:  order = "cba", s = "abcd" 
Output:  "cbad" 
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
*/

//Optimized
string customSortString(string order, string s) {
    string custom;
    vector<int> freq(26, 0);
    for (char c: s) {
        freq[c - 'a']++;
    }
    for (char c: order) {
        while (freq[c - 'a']) {
            custom += c;
            freq[c - 'a']--;
        }
    }
    for (int i = 0; i < 26; i++) {
        while (freq[i]) {
            custom += i + 'a';
            freq[i]--;
        }
    }
    return custom;
}

string customSortString(string order, string s) {
    unordered_map<char,int> m;
    int i,cur,tmp;
    for(i=0;i<order.size(); i++){
        m[order[i]] = i;
    }
    i = 1;
    string ans;
    ans = s[0];
    while(i<s.length()){

        if(m.find(s[i])!=m.end()){
            cur = m[s[i]];
        }else{
            cur = -1;
        }

        if(cur == -1){
            ans.push_back(s[i++]);
            continue;
        }
        tmp = 0;
        while(tmp<ans.length() && (m.find(ans[tmp])==m.end() || m[ans[tmp]] < cur)){
            tmp++;
        }
        if(tmp != ans.length()){
            ans.insert(ans.begin()+tmp, s[i]);
        }else{
            ans.push_back(s[i]);
        }
        i++;

    }
    return ans;
}

int main(){

    string order = "cba";
    string s = "abcd";
    cout<<customSortString(order, s);

    return 0;
}