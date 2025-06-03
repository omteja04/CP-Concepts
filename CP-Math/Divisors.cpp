/**
 * Author: omteja04
 * Created on: 23-08-2024 08:01:14
 * Description: Divisors
 **/

#include <iostream>
#include <vector>

// ITERATE ON DIVISORS
// n*sqrt(n)

int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i)
                cnt++;
        }
    }
    return cnt;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> div(n + 1);
    // ITERATE ON MULTIPLES
    // n*log(n)
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            div[j]++; // i is the divisor of j
        }
    }

    // for (int i = 1; i <= n; i++) {
    std::cout << div[n] << std::endl;
    std::cout << countDivisors(n) << std::endl;
}
