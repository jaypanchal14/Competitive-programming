#include <iostream>
#include <vector>
#include <algorithm>

/*
Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example:
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

using namespace std;

string longestCommonPrefix(vector<string> &strs){
    string ans = "";
    int mini = 201;
    int size = strs.size();
    for (string str : strs){
        if (str.size() > 0){
            if (mini > str.size()){
                mini = str.size();
            }
            // mini = min(mini, str.size());
        }
        else{
            return "";
        }
    }
    for (int i = 0; i < mini; i++){
        char c = strs[0].at(i);
        bool b = false;
        cout << "char is:" << c << ", b:" << b << endl;

        for (int j = 1; j < size; j++){
            if (strs[j].at(i) != c){
                b = true;
                break;
            }
        }
        if (b){
            break;
        }
        ans.push_back(c);
    }
    return ans;
}

int main()
{
    vector<string> v = {"flower","flow","flight"};
    cout<<longestCommonPrefix(v);
    return 0;
}