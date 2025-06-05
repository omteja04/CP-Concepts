/**
 * Author: omteja04
 * Created on: 04-06-2025 13:53:27
 * Problem: LongestHappyPrefix
 * Link: https://leetcode.com/problems/longest-happy-prefix/
 **/

#include <bits/stdc++.h>
using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

using ll = long long;
const int MOD = 1e9 + 7;  // Large prime modulus
const int BASE = 31;      // Base for polynomial hash
                          //
inline ll modAdd(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}

inline ll modSub(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a - b + mod) % mod;
}

inline ll modMul(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

inline ll power(ll base, ll exp, const ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) {
            res = modMul(res, base, mod);
        }
        base = modMul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

inline ll modInverse(ll a, ll m = MOD) {
    return power(a, m - 2, m);
}

struct SingleHash {
    string s;
    int n;
    vector<ll> prefixHash;
    vector<ll> power;

    SingleHash(const string &str) {
        s = ' ' + str;
        n = (int) s.size();
        prefixHash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            power[i] = modMul(power[i - 1], BASE, MOD);
            prefixHash[i] = modAdd(modMul(prefixHash[i - 1], BASE, MOD), s[i] - 'a' + 1, MOD);
        }
    }

    ll getHash(int l, int r) {
        //  ll hashValue = prefixHash[r + 1] - (prefixHash[l] * power[r - l +1]) % MOD;
        ll hashValue = modSub(prefixHash[r], modMul(prefixHash[l - 1], power[r - l + 1], MOD), MOD);
        return hashValue;
    }
};

string longestPrefix(string s) {
    SingleHash H(s);
    int n = s.size();
    string res;
    for(int i = n - 1; i >= 1; i--) {
        ll hashVal = H.getHash(1, i);
        ll suffixHashVal = H.getHash(n - i + 1, n);
        if(hashVal == suffixHashVal) {
            return s.substr(0, i);
        }
    }
    return "";
}

void levi() {
    string str;
    cin >> str;
    string res = longestPrefix(str);
    cout << res;
}

int main() {
    levi();
}
