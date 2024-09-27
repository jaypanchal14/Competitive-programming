#include<vector>
#include<unordered_map>

using namespace std;

/*
Description:
Given the string s, return the size of the longest substring containing each vowel an even number of times.
That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
*/

class Solution {
public:

    /*
    To find the length of substring based on computed mask from vowels only, we are not considering the consonants
    in the computation.
    If the mask exists, means we can take the substring from the previous index to current, excluding previous index.
    */
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        int ans = 0, n = s.size(), tmp = 0;
        m[0] = -1;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                //Here, s[i]-'a' will not work, as consonants and character 'a' will behave the same
                //so, we are adding 1 to the value
                tmp ^= (s[i]-'a'+1);                
            }
            if(m.find(tmp)!=m.end()){
                ans = max(ans, i-m[tmp]);
            }else{
                m[tmp] = i;
            }
        }
        return ans;
    }
};