/**
 * Author: omteja04
 * Created on: 27-09-2024 22:36:11
 * Description: maxXorQueries
 **/
#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;

/* https://leetcode.com/problems/maximum-xor-with-an-element-from-array/ */
struct Node {
    Node *links[2];
    bool containsKey(int bit) { return links[bit] != nullptr; }
    void put(int bit, Node *node) { links[bit] = node; }
    Node *get(int bit) { return links[bit]; }
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
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> offlineQueries;
    // An offline algorithm allows us to manipulate the data to be queried before
    // any answer is printed.
    // This is usually only possible when the queries do not update the original
    // element set before printing the result.
    for (int i = 0; i < queries.size(); i++) {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    int n = arr.size();

    sort(offlineQueries.begin(), offlineQueries.end());
    vector<int> ans(queries.size(), 0);
    int ind = 0;
    Trie trie;
    for (int i = 0; i < offlineQueries.size(); i++) {
        int ai = offlineQueries[i].first;
        int xi = offlineQueries[i].second.first;
        int qInd = offlineQueries[i].second.second;
        while (ind < n && arr[ind] <= ai) {
            trie.insert(arr[ind]);
            ind++;
        }
        if (ind == 0)
            ans[qInd] = -1;
        else {
            ans[qInd] = trie.getMax(xi);
        }
    }
    return ans;
}
int main() {

    return 0;
}