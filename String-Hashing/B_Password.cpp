/**
 * Author: omteja04
 * Created on: 04-06-2025 17:41:53
 * Problem: B_Password
 * Link: https://codeforces.com/problemset/problem/126/B
 **/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define int long long
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

const int MOD = 1e9 + 7;
const int BASE = 31;
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

struct Hashing {
    string s;
    ll n;
    vector<ll> prefixHash, power;
    Hashing(const string &str) {
        s = ' ' + str;
        n = s.size();
        prefixHash.resize(n + 1, 0);
        power.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            power[i] = modMul(power[i - 1], BASE);
            prefixHash[i] = modAdd(modMul(prefixHash[i - 1], BASE), s[i] - 'a' + 1);
        }
    }
    ll getHash(int l, int r) {
        return modSub(prefixHash[r], modMul(prefixHash[l - 1], power[r - l + 1]));
    }
};

bool can(int len, Hashing &h) {
    ll hashOfPref = h.getHash(1, len);
    for(int i = 2; i + len - 1 < h.n - 1; i++) {
        if(h.getHash(i, len + i - 1) == hashOfPref) {
            return true;
        }
    }
    return false;
}

void levi() {
    string str;
    cin >> str;
    vector<int> sizesOfPrefSuf;
    Hashing H(str);
    int n = str.size();
    for(int i = 1; i < n; i++) {
        ll hashVal = H.getHash(1, i);
        ll suffixHashVal = H.getHash(n - i + 1, n);
        if(hashVal == suffixHashVal) {
            sizesOfPrefSuf.push_back(i);
        }
    }
    // for(auto &it: sizesOfPrefSuf) {
    //     cout << it << " ";
    // }

    //  Now Binary Search

    int low = 0;
    int high = sizesOfPrefSuf.size() - 1;
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(can(sizesOfPrefSuf[mid], H)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(ans == -1) {
        cout << "Just a legend";
        return;
    }
    cout << str.substr(0, sizesOfPrefSuf[ans]);
}

#undef int
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
