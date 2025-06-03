/**
 * Author: omteja04
 * Created on: 25-08-2024 13:36:39
 * Description: LinearSieve
 **/
#include <iostream>
#include <vector>
// const int N = 10000000;
std::vector<int> lp(10 + 1, 0); // minPrimeFactor
std::vector<int> primes;
void sieve(int N) {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= N; j++) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }
    for (int i : lp) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i : primes) {
        std::cout << i << " ";
    }
}
int main() {
    sieve(10);
}