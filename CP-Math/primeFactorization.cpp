/**
 * Author: omteja04
 * Created on: 25-08-2024 15:31:27
 * Description: primeFactorization
 **/
#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> primefactors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primefactors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        primefactors.push_back(n);
    }
    for(int i: primefactors){
        std::cout<<i<<std::endl;
    }
}