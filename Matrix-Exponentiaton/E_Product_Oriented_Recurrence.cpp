/**
 * Author: omteja04
 * Created on: 01-06-2025 19:44:58
 * Problem: E_Product_Oriented_Recurrence
 * Link: https://codeforces.com/contest/1182/problem/E
 **/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

using Matrix = vector<vector<ll>>;
#define int long long
Matrix operator*(Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix generateIdentity(ll n) {
    Matrix I(n, vector<long long>(n, 0));
    for(int i = 0; i < n; ++i) {
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
void levi() {
    int n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    if(n == 1) {
        cout << f1 % MOD;
        return;
    }
    if(n == 2) {
        cout << f2 % MOD;
        return;
    }
    if(n == 3) {
        cout << f2 % MOD;
        return;
    }
    
}
#undef int
int main() {
    fast_cin();
    int tc;
    cin >> tc;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
