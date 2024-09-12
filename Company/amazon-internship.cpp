#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* OA - two questions
Que-1 : 
You are given an array of size n, where ith index represents how many parcels ith delivery person currently has.
You are also given an integer extra_parcels, indicating extra parcels which needs to be delivered.
Distribute the extra_parcels such that the maximum parcel hold by the delivery person is minimum.
Output:
Return the maximum parcel count from all the persons.
*/

int getMaximum(vector<int> parcels, int extra_parcels){
    int n = parcels.size(), tmp;
    int maxi = *max_element(parcels.begin(), parcels.end());
    int ans = maxi;
    for(int i=0; i<n; i++){
        tmp = maxi - parcels[i];
        if(extra_parcels >= tmp){
            extra_parcels -= tmp;
        }else{
            extra_parcels = 0;
            return ans;
        }
    }
    int quotient = extra_parcels / n + (extra_parcels % n > 0 ? 1 : 0);
    return ans + quotient;

    /*
    Another way to do is, get the sum of parcels from the vector.
    if(maxi * n >= total_sum + extra_parcels){
        return maxi;
    }
    total_sum += extra_parcels;
    maxi = total_sum / n + (total_sum % n > 0 ? 1 : 0);
    return maxi;
    */
}

/*
Que-2 : Given a text and a regular expression that only contains one wildcard character '*' 
(which matches any string), return the length of the longest matched substring in the text. 
Return -1 if no answer can be found. 1 <= |Text|, |Regex| <= 10^6.
Example:
Input : text = "abcerfabc", regex = "abc*abc"
Output : 9 (As, * will match for "erf" characters)
*/
int maxMatchLength(const string& text, const string& regex){
    int m = text.size(), n = regex.size();
    if(n == 1){
        return m;
    }
    int pos = regex.find('*');
    if(pos == 0){
        // '*' is at beginning
        string right = regex.substr(1);
        size_t f = text.rfind(right);
        if(f == string::npos){
            return -1;
        }
        return f + right.size();
    }else if(pos == n-1){
        // '*' is at end
        string left = regex.substr(0, pos);
        size_t f = text.find(left);
        if(f == string::npos){
            return -1;
        }
        return m-f;
    }else{
        // '*' is in between
        string right = regex.substr(pos+1);
        size_t rf = text.rfind(right);
        if(rf == string::npos){
            return -1;
        }
        string left = regex.substr(0, pos);
        size_t lf = text.find(left);
        if(lf == string::npos){
            return -1;
        }
        if(lf + left.size()-1 >= rf){
            return -1;
        }
        return rf + right.size() - lf;
    }
}

/*
Interview : 
1) Group anagram : Leetcode 49
2) Closest 3 sum : Leetcode 16
*/

int main(){
    string text = "abcbc";
    string regex = "*cbc";
    cout << maxMatchLength(text, regex) << endl;
}