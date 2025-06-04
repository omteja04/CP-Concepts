/**
 * Author: omteja04
 * Created on: 03-06-2025 21:16:29
 * Template: String Hashing
 **/
#include <bits/stdc++.h>
using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

using ll = long long;

const int MAX = 1e6 + 5;

// MOD values for hashing (large primes)
vector<ll> MOD = {127657753, 987654319};

// BASE values for hashing (randomly chosen)
vector<ll> BASE = {137, 277};

const int HASH_COUNT = MOD.size();

// Precomputed powers and inverse powers for each hash function
vector<vector<ll>> pw(HASH_COUNT, vector<ll>(MAX));
vector<vector<ll>> ipw(HASH_COUNT, vector<ll>(MAX));

// Modular addition
ll modAdd(ll a, ll b, const ll mod) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}

// Modular subtraction
ll modSub(ll a, ll b, const ll mod) {
    a %= mod;
    b %= mod;
    return (a - b + mod) % mod;
}

// Modular multiplication
ll modMul(ll a, ll b, const ll mod) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

// Modular exponentiation
ll power(ll base, ll exp, const ll mod) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's little theorem (mod must be prime)
ll modInverse(ll a, ll m) {
    return power(a, m - 2, m);
}

// Precompute powers and inverse powers of each BASE modulo MOD
void precompute_hash_helpers() {
    for(int h = 0; h < HASH_COUNT; ++h) {
        pw[h][0] = 1;
        ipw[h][0] = 1;
        ll inv = modInverse(BASE[h], MOD[h]);  // Modular inverse of BASE[h]
        for(int i = 1; i < MAX; ++i) {
            pw[h][i] = (pw[h][i - 1] * BASE[h]) % MOD[h];
            ipw[h][i] = (ipw[h][i - 1] * inv) % MOD[h];
        }
    }
}

struct Hashing {
    int n;
    string s;
    vector<vector<ll>> prefixHash;

    Hashing(const string &_s) {
        s = _s;
        n = s.size();
        prefixHash.assign(HASH_COUNT, vector<ll>(n + 1, 0));

        for(int h = 0; h < HASH_COUNT; ++h) {
            for(int i = 1; i <= n; ++i) {
                prefixHash[h][i] = (prefixHash[h][i - 1] + pw[h][i - 1] * (ll) (s[i - 1])) % MOD[h];
            }
        }
    }

    // Get hash of substring s[l-1..r-1] (1-based indexing)
    vector<ll> getHash(int l, int r) {
        assert(1 <= l && l <= r && r <= n);
        vector<ll> hash(HASH_COUNT);
        for(int h = 0; h < HASH_COUNT; ++h) {
            ll diff = modSub(prefixHash[h][r], prefixHash[h][l - 1], MOD[h]);
            hash[h] = (diff * ipw[h][l - 1]) % MOD[h];
        }
        return hash;
    }

    // Get hash of the entire string
    vector<ll> fullHash() {
        return getHash(1, n);
    }
};

void levi() {
    precompute_hash_helpers();

    string str = "aqaq";
    Hashing h(str);

    // Store distinct substrings by their hash vectors
    set<vector<ll>> distinct_substrings;
    int n = str.size();

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            distinct_substrings.insert(h.getHash(i, j));
        }
    }

    cout << "Number of distinct substrings: " << distinct_substrings.size() << '\n';
    vector<ll> res = h.fullHash();
    for(auto &it: res) {
        cout << it << " ";
    }
    // cout << '\n';
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        levi();
        cout << "\n";
    }
    return 0;
}
