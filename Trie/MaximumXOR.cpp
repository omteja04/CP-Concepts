/**
 * Author: omteja04
 * Created on: 27-09-2024 15:44:37
 * Description: MaximumXOR
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;
struct Node {
    Node *links[2];
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    void put(int bit, Node *node) {
        links[bit] = node;
    }
    Node *get(int bit) {
        return links[bit];
    }
};
class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int x) {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!node->containsKey(1 - bit)) {
                node = node->get(bit);
            } else {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            }
        }
        return maxNum;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    for (int &it : arr1) {
        trie.insert(it);
    }
    int maxi = 0;
    for (int &it : arr2) {
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}
int main() {

    return 0;
}