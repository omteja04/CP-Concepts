#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;

void levi() {

    int n;
    cin >> n;
    bool seive[n + 2];
    memset(seive, 1, sizeof(seive));
    seive[0] = seive[1] = 0;

    for (int i = 2; i * i <= n + 1; i++) {
        if (seive[i] == 1) {
            for (int j = i * i; j <= n + 1; j += i) {
                seive[j] = 0;
            }
        }
    }

    if (n > 2) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
    for (int i = 2; i <= n + 1; i++) {
        if (seive[i]) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
    }
    cout << '\n';
}

int main() {
    levi();
    return 0;
}
