/**
 * Author: omteja04
 * Created on: 05-02-2025 18:17:21
 * Description: Primes
 **/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
bool blackBox[(long long) 5000001];
vector<ll> buildSieve() {
    vector<ll> primeNumbers;
    blackBox[0] = blackBox[1] = false;
    for(ll i = 2; i * i <= 500000; i++) {
        if(blackBox[i]) {
            for(ll j = i * i; j <= 500000; j += i) {
                blackBox[j] = false;
            }
        }
    }

    for(ll i = 2; i <= 500000; i++) {
        if(blackBox[i]) {
            // cerr << i << " ";
            primeNumbers.push_back(i);
        }
    }
    return primeNumbers;
}
int main() {

    ll q;
    cin >> q;
    memset(blackBox, true, sizeof(blackBox));
    vector<ll> primeNumbers = buildSieve();
    vector<ll> inp(q);
    for(ll i = 0; i < q; i++) {
        cin >> inp[q];
    }
}
