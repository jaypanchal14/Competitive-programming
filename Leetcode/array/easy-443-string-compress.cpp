#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
Objective :
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
*/

int compress(vector<char> &chars){
    int i = 0;
    int ansIndex = 0;
    int size = chars.size();
    while(i<size){
        int j = i+1;
        while(j<size && chars[i]==chars[j]){
            j++;
        }
        chars[ansIndex++] = chars[i];
        if(j-i > 1){
            string count = to_string(j-i);
            for(char cc : count){
                chars[ansIndex++] = cc;
            }
        }
        i = j;
    }
    return ansIndex;
}


//With extra space
int compressWithNewSpace(vector<char> &chars)
{
    string res;
    int count = 1, tmp = chars[0];
    int size = chars.size();
    int i = 1;
    while (i < size){
        if (tmp == chars[i]){
            count++;
        }
        else
        {
            if (count == 1){
                res.push_back(tmp);
            }
            else{
                res.push_back(tmp);
                res += to_string(count);
            }
            tmp = chars[i];
            count = 1;
        }
        i++;
    }
    if (count == 1){
        res.push_back(tmp);
    }
    else{
        res.push_back(tmp);
        res += to_string(count);
    }
    // cout<<"Final string: "<<res<<endl;
    int newSize = res.size();
    for(int j=0;j<newSize;j++){
        chars[j] = res[j];
    }
    return newSize;
}

int main()
{

    int sz;
    cin >> sz;
    vector<char> v;
    for (int i = 0; i < sz; i++)
    {
        char c;
        cin >> c;
        v.push_back(c);
    }
    //cout << "Size after compression : " << compressWithNewSpace(v) << endl;
    cout << "Size after compression : " << compress(v) << endl;
    for(char c: v){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}