/**
 * Author: omteja04
 * Created on: 25-09-2024 07:32:22
 * Description: ImplementTrie-1
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;

struct Node {
    // Assuming all letters are lowercase
    Node *links[26];
    bool flag = false;
    bool containsKey(char &ch) {
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
    /* Initialize your data structure here */
    Trie() {
        root = new Node();
    }
    /* Inserts a word into the Trie */

    // TC: O(len(word))
    void insert(string &word) {
        Node *node = root; // Temporary node
        for (auto &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            // Moves to Reference Trie
            node = node->get(ch);
        }
        // Word has been ended
        node->setEnd();
    }

    /* returns true if the word is in the Trie */

    // TC: O(len(word))
    bool search(string &word) {
        Node *node = root; // Temporary node
        for (auto &ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    /* returns true if there is any word in the Trie that start with the given prefix */

    // TC: O(len(prefix))
    bool startsWith(string &prefix) {
        Node *node = root; // Temporary node
        for (auto &ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

int main() {

    return 0;
}