#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)
using Matrix = vector<vector<ll>>;
const int MOD = 1e9 + 7;
Matrix multiply(const Matrix &a, const Matrix &b) {
    int n = a.size();
    Matrix result(n, vector<long long>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}
Matrix power(Matrix base, int exp) {
    int n = base.size();
    Matrix res(n, vector<ll>(n));
    for(int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while(exp) {
        if(exp % 2) {
            res = multiply(res, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}
void levi() {
    Matrix T = {{1, 1}, {1, 0}};
    ll n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return;
    }
    Matrix res = power(T, n - 1);
    cout << res[0][0];
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
