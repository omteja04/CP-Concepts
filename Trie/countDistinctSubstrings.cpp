/**
 * Author: omteja04
 * Created on: 27-09-2024 00:05:57
 * Description: countDistinctSubstrings
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;
struct Node {
    Node *links[26];
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s) {
    //    Write your code here.
    Node *root = new Node();
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        Node *node = root;
        for (int j = i; j < s.length(); j++) {
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}
int main() {
    string s;
    cin >> s;
    cout << countDistinctSubstrings(s);
    return 0;
}