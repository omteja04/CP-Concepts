/**
 * Author: omteja04
 * Created on: 23-05-2025 22:57:46
cSpell:disable
 * Problem: RabinKarp
 **/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int d = 256;

int calculateHash(const string &s, int len) {
    int hash = 0;

    for(int i = 0; i < len; i++) {
        hash = (1LL * hash * d + s[i]) % mod;
    }
    return hash;
}

int rollingHash(int oldHash, char oldChar, char newChar, int powD) {
    int newHash = (1LL * d * ((oldHash - 1LL * oldChar * powD % mod + mod) % mod) + newChar) % mod;
    return newHash;
}

bool checkMatch(const string &text, const string &pattern, int start) {
    for(int i = 0; i < pattern.length(); i++) {
        if(text[start + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}
void RabinKarpSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    if(m > n) {
        cout << 0;
        return;
    }
    int h = 1;
    for(int i = 0; i < m - 1; i++) {
        h = (1LL * h * d) % mod;
    }
    int patternHash = calculateHash(pattern, m);
    int windowHash = calculateHash(text, m);
    int cnt = 0;
    for(int i = 0; i <= n - m; i++) {
        if(patternHash == windowHash && checkMatch(text, pattern, i)) {
            // cout << "Hi";
            cnt++;
        }
        if(i < n - m) {
            windowHash = rollingHash(windowHash, text[i], text[i + m], h);
        }
    }
    cout << cnt;
}

int main() {
    string text = "abdabcbabc";
    string pattern = "abc";
    RabinKarpSearch(text, pattern);
    return 0;
}
