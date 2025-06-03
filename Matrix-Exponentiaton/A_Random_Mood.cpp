/**
 * Author: omteja04
 * Created on: 28-05-2025 17:38:42
 * Problem: A_Random_Mood
 * Link: https://codeforces.com/gym/102644/problem/A
 **/
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using Matrix = vector<vector<ld>>;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

Matrix multiply(const Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ld>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]);
            }
        }
    }
    return res;
}
Matrix power(Matrix &base, ll exp) {
    ll n = base.size();
    Matrix res(n, vector<ld>(n));
    for(int i = 0; i < n; i++) {
        res[i][i] = 1.0;
    }
    while(exp) {
        if(exp & 1) {
            res = multiply(res, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}
void levi() {
    ll n;
    ld p;
    cin >> n >> p;
    Matrix T = {{1 - p, p},
                {p, 1 - p}};
    Matrix res = power(T, n);
    cout << fixed << setprecision(10) << res[0][0];
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
