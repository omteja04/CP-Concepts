/**
 * Author: omteja04
 * Created on: 25-08-2024 15:47:38
 * Description: A_Almost_Prime
**/

/**
 * Author: omteja04
 * Created on: 25-08-2024 15:35:16
 * Description: A_Almost_Prime
 **/

/* A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not.
Find the amount of almost prime numbers which are between 1 and n, inclusive. */

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define coutArr(n, arr)        \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '
using ll = long long;
using v32 = vector<int>;
const int MOD = 1000000007;

void isIt(int num, int &cnt) {
    unordered_set<int> s;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            s.insert(i);
            num /= i;
        }
    }
    if (num > 1) {
        s.insert(num);
    }
    cnt += s.size() == 2 ? 1 : 0;
}
void levi() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << 0;
        return;
    }
    int cnt = 0;
    for (int i = 4; i <= n; i++) {
        isIt(i, cnt);
    }
    cout << cnt;
}

int main() {
    levi();
    return 0;
}