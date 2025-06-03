/**
 * Author: omteja04
 * Created on: 23-08-2024 22:44:34
 * Description: ModularArithmetic
 **/

/*

(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD
(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD
(a - b) % MOD = ((a % MOD) - (b % MOD) + MOD) % MOD


 */
#include <iostream>
// O(log(b))
long long binaryExponentiation(int a, int b, int mod) {
    if (b == 0)
        return 1;
    long long res = binaryExponentiation(a, b / 2, mod);
    res = 1LL * res * res % mod;
    if (b & 1) {
        return (1LL * a * res % mod);
    }
    return res;
}
int main() {
    int a, b, mod;
    std::cin >> a >> b >> mod;
    std::cout << binaryExponentiation(a, b, mod);
}