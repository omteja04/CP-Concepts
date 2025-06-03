/**
 * Author: omteja04
 * Created on: 23-08-2024 22:00:41
 * Description: LCMandHCF
 **/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
/*
Co-prime => gcd(a,b) = 1
gcd(a,b) = gcd(a, b - a) b > a
gcd(a,b) = =gcd(b%a, a)
O(log(max(a,b))
 */
int findGCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << findGCD(a, b) << std::endl;
}
