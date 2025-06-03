/**
 * Author: omteja04
 * Created on: 03-06-2025 20:52:12
 * Template: Matrix-Exponentiation
 **/

#include <bits/stdc++.h>
using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

template <typename T>
using Matrix = vector<vector<T>>;
using ll = long long;
const int MOD = 1e9 + 7;

struct MatrixExpo {
    int n;
    int mod;

    MatrixExpo(int size, int m = MOD):
        n(size), mod(m) {}

    Matrix<ll> multiply(const Matrix<ll> &a, const Matrix<ll> &b) {
        Matrix<ll> res(n, vector<ll>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix<ll> identity() {
        Matrix<ll> I(n, vector<ll>(n, 0));
        for(int i = 0; i < n; ++i) {
            I[i][i] = 1;
        }
        return I;
    }

    Matrix<ll> power(Matrix<ll> base, ll exp) {
        Matrix<ll> res = identity();
        while(exp) {
            if(exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
};

void solve() {
    ll n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return;
    }

    Matrix<ll> T = {{1, 1}, {1, 0}};
    MatrixExpo matrixExpo(2);
    Matrix<ll> res = matrixExpo.power(T, n - 1);
    cout << res[0][0];  // Fibonacci(n)
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
        cout << '\n';
    }
    return 0;
}
