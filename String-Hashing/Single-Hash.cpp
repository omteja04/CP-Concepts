/**
 * Author: omteja04
 * Created on: 03-06-2025 21:34:20
 * Problem: Single-Hash
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
        s = str;
        n = (int) s.size();
        prefixHash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        precomputePowers();
        computePrefixHashes();
    }

    void precomputePowers() {
        for(int i = 1; i <= n; i++) {
            power[i] = modMul(power[i - 1], BASE, MOD);
        }
    }

    void computePrefixHashes() {
        for(int i = 0; i < n; i++) {
            // prefixHash[i + 1] = (prefixHash[i] * BASE + (s[i] - 'a' + 1)) % MOD;
            prefixHash[i + 1] = modAdd(modMul(prefixHash[i], BASE, MOD), (s[i] - 'a' + 1), MOD);
        }
    }

    ll getHash(int l, int r) {
        //  ll hashValue = prefixHash[r + 1] - (prefixHash[l] * power[r - l + 1]) % MOD;
        ll hashValue = modSub(prefixHash[r + 1], modMul(prefixHash[l], power[r - l + 1], MOD), MOD);
        return hashValue;
    }
};

void levi() {
    string text = "abdabcbabc";
    SingleHash hash(text);

    cout << "Hash of entire string: " << hash.getHash(0, (int) text.size() - 1) << "\n";
    cout << "Hash of substring 'abc' at index 7..9: " << hash.getHash(7, 9) << "\n";
    cout << "Hash of substring 'dab' at index 2..4: " << hash.getHash(2, 4) << "\n";

    return;
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
