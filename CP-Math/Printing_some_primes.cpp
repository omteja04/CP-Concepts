/**
 * Author: omteja04
 * Created on: 25-08-2024 14:59:20
 * Description: Printing_some_primes
 **/

#include <iostream>
#include <vector>
const int N = 1e8;
const int MOD = 100;

std::vector<int> pr;
std::vector<int> lp(N + 1, 0);
int main() {
    // std::memset(pr, 1, sizeof(pr));
    for (long long i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= N; j++) {
            lp[pr[j] * i] = pr[j];
            if (lp[i] == pr[j]) {
                break;
            }
        }
    }

    for (int i = 1; i <= pr.size(); i++) {
        if (i % MOD == 1) {
            std::cout << pr[i - 1] << std::endl;
        }
    }
}