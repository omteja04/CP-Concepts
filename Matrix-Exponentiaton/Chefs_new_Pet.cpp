/**
 * Author: omteja04
 * Created on: 01-06-2025 17:48:34
 * Problem: Chefs_new_Pet
 * Link: https://www.codechef.com/problems/HAREJUMP
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
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(k);
    for(auto &it: arr) {
        cin >> it;
    }
    vector<int> dp(16);
    dp[0] = 1;
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= 15; i++) {
        for(int j = 0; j < k; j++) {
            if(i - arr[j] >= 0) {
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
            }
        }
    }
    if(n <= 15) {
        cout << dp[n];
        return;
    }
    // cout << "Hi";
    Matrix T(15, vector<int>(15, 0));
    for(int i = 0; i < k; i++) {
        T[0][arr[i] - 1] = 1;
    }
    for(int i = 1; i < 15; i++) {
        T[i][i - 1] = 1;
    }
    Matrix res = power(T, n - 15);
    int value = 0;
    for(int i = 0; i < 15; i++) {
        value = (value + (res[0][i] * dp[15 - i]) % MOD) % MOD;
    }
    cout << value;
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
