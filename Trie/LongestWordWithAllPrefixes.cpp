/**
 * Author: omteja04
 * Created on: 26-09-2024 15:10:45
 * Description: LongestWordWithAllPrefixes
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;
struct Node {
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node *node = root;
        for (char &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool checkIfThePrefixExists(string &word) {
        Node *node = root;
        for (char &ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
            if (node->isEnd() == false)
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a) {
    Trie trie;
    for (auto &word : a) {
        trie.insert(word);
    }
    string longest = "";
    for (string &word : a) {
        if (trie.checkIfThePrefixExists(word)) {
            if (word.length() > longest.length()) {
                longest = word;
            } else if (word.length() == longest.length() && word < longest) {
                longest = word;
            }
        }
    }
    if (longest == "") {
        return "None";
    }
    return longest;
}
int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (string &word : words) {
        cin >> word;
    }
    cout << completeString(n, words) << endl;
    return 0;
}