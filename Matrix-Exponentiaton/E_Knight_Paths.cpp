/**
 * Author: omteja04
 * Created on: 28-05-2025 23:17:46
 * Problem: E_Knight_Paths
 * Link: https://codeforces.com/gym/102644/problem/E
 **/

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)
using u32 = uint32_t;
using ll = long long;
const ll N = 8;
const ll SIZE = N * N;
// vector<pair<ll, ll>> dirs = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
using Matrix = vector<vector<u32>>;

Matrix operator*(Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<u32>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            for(ll k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]);
            }
        }
    }
    return res;
}

Matrix generateIdentity(ll n) {
    Matrix I(n, vector<u32>(n, 0));
    for(ll i = 0; i < n; ++i) {
        I[i][i] = 1;
    }
    return I;
}
Matrix power(Matrix &base, ll exp) {
    Matrix res = generateIdentity(base.size());
    while(exp) {
        if(exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}
ll flatten(ll i, ll j) {
    return i * 8 + j;
}
bool inside(ll i, ll j) {
    return 0 <= min(i, j) && max(i, j) < 8;
}
void levi() {
    ll k;
    cin >> k;
    u32 total = 0;

    Matrix T(65, vector<u32>(65, 0));
    for(ll row = 0; row < 8; row++) {
        for(ll col = 0; col < 8; col++) {
            for(int dr: {-2, -1, 1, 2}) {
                for(int dc: {-2, -1, 1, 2}) {
                    if(abs(dr) != abs(dc)) {
                        int newRow = row + dr;
                        int newCol = col + dc;
                        if(inside(newRow, newCol)) {
                            ll from = flatten(row, col);
                            ll to = flatten(newRow, newCol);
                            T[from][to] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i <= 64; i++) {
        T[i][64] = 1;
    }
    Matrix res = power(T, k + 1);
    cout << res[0][64];

    // vector<u32> dp(65, 0);
    // dp[0] = 1;
    // for(ll term = 0; term <= k; term++) {
    //     vector<u32> new_dp(65, 0);
    //     for(ll row = 0; row < 8; row++) {
    //         for(ll col = 0; col < 8; col++) {
    //             for(int dr: {-2, -1, 1, 2}) {
    //                 for(int dc: {-2, -1, 1, 2}) {
    //                     if(abs(dr) != abs(dc)) {
    //                         int newRow = row + dr;
    //                         int newCol = col + dc;
    //                         if(inside(newRow, newCol)) {
    //                             new_dp[flatten(newRow, newCol)] += dp[flatten(row, col)];
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     new_dp[64] += dp[64];
    //     for(ll row = 0; row < 8; row++) {
    //         for(ll col = 0; col < 8; col++) {
    //             new_dp[64] += dp[flatten(row, col)];
    //         }
    //     }

    //     dp = new_dp;
    // }

    // cout << dp[64];
}

int main() {
    fast_cin();
    ll tc = 1;
    // cin >> tc;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
