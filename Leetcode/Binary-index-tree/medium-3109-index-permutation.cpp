#include <iostream>
#include <vector>

using namespace std;
#define MOD 1000000007

/*
Description :           PREMIUM
Given an array perm of length n which is a permutation of [1,2,..,n], return the index of perm in the
lexicographically sorted order of all the permutations of [1,2,..,n].
Since the answer may be very large, return it modulo 10^9+7.
Example:
Input : perm = [3,1,2]
Output : 4
*/

class BIT{
public:

    vector<int> bit_;

    BIT(int n) : bit_(n + 1){

    }

    void add(int i, int val){
        ++i;
        for (; i < bit_.size(); i += lower_bit(i)){
            bit_[i] = (bit_[i] + val) % MOD;
        }
    }

    int query(int i) const{
        ++i;
        int total = 0;
        for (; i > 0; i -= lower_bit(i)){
            total = (total + bit_[i]) % MOD;
        }
        return total;
    }

private:
    inline int lower_bit(int i) const{
        return i & -i;
    }

};

int getPermutationIndex(vector<int> &v)
{
    int ans = 0;
    vector<int> fact(v.size() + 1, 1);
    for (int i = 2; i <= v.size(); i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    BIT bit(v.size());
    for (int i = 0; i < v.size(); ++i)
    {
        ans = (ans + (static_cast<int64_t>((((v[i] - 1) - bit.query((v[i] - 1) - 1)) % MOD + MOD) % MOD) * fact[(v.size() - 1) - i] % MOD)) % MOD;
        bit.add(v[i] - 1, +1);
    }
    return ans % MOD;
}

int main()
{
    vector<int> v = {3, 2, 4, 1};
    cout << "Index of current permuation is: " << getPermutationIndex(v) << endl;
    return 0;
}