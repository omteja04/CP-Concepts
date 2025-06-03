/**
 * Author: omteja04
 * Created on: 23-08-2024 20:18:52
 * Description: SieveOfEratosthenes
 **/

#include <iostream>
#include <ostream>

// O(n*log(log(n)))
bool primes[(long long) (1e7) + 1];
void sieve(int n) {
    for(int i = 2; i <= n; i++) {
        primes[i] = true;
    }

    primes[0] = primes[1] = false;

    for(int i = 2; i * i <= n; i++) {  // Loop until the square root of n
        if(primes[i]) {
            for(int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    // return primes[n]; // Returns 1 if n is prime, 0 otherwise

    // prime[x] => stores whether x is prime or not
}
int primeNum[(long long) 1e7 + 1];
void sieve2(int n) {
    for(int i = 0; i <= n; i++) {
        primeNum[i] = i;
    }
    for(int i = 2; i * i < n; i++) {
        if(primeNum[i]) {
            for(int j = i * i; j <= n; j += i) {
                if(primeNum[j] == j) {
                    primeNum[j] = i;
                }
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    sieve(n);
    sieve2(n);
    std::cout << "Factors upto N: ";
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Total Factors of N: ";
    int temp = n;
    while(temp > 1) {
        std::cout << primeNum[temp] << " ";
        temp /= primeNum[temp];
    }
}
