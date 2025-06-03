/**
 * Author: omteja04
 * Created on: 30-05-2025 19:38:43
 * Problem: F_Min_Path
 * Link: https://codeforces.com/gym/102644/problem/F
 **/

#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
const long long INF = LLONG_MAX / 2;
#define fast_cin()                         \
std::ios_base::sync_with_stdio(false); \
std::cin.tie(NULL);                    \
std::cout.tie(NULL)

using ll = long long;
using Matrix = vector<vector<ll>>;
Matrix operator*(Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                // res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

Matrix generateIdentity(ll n) {
    Matrix I(n, vector<long long>(n, INF));
    for(int i = 0; i < n; ++i) {
        I[i][i] = 0;
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
void levi() {
    ll vertices, edgeCnt, pathLength;
    cin >> vertices >> edgeCnt >> pathLength;
    Matrix adj(vertices, vector<ll>(vertices, INF));
    for(int i = 0; i < edgeCnt; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        auto src = u;
        auto dest = v;
        adj[src - 1][dest - 1] = c;
    }

    Matrix res = power(adj, pathLength);
    ll ans = INF;
    for(auto &row: res) {
        for(auto &val: row) {
            ans = min(ans, val);
        }
    }
    if(ans >= INF / 2) {
        cout << "IMPOSSIBLE";
    } else {

        cout << ans;
    }
}

int main() {
    fast_cin();
    int tc = 1;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
