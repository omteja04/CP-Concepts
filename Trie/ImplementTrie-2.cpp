/**
 * Author: omteja04
 * Created on: 25-09-2024 18:58:37
 * Description: ImplementTrie-2
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;

class Node {
private:
    Node *links[26];
    bool flag;
    int cntEndsWith;
    int cntPrefix;

public:
    Node() {
        flag = false;
        for (long unsigned int i = 0; i < 26; i++)
            links[i] = nullptr;
        cntEndsWith = 0;
        cntPrefix = 0;
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void increaseEnd() {
        cntEndsWith++;
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void deleteEnd() {
        cntEndsWith--;
    }
    void decreasePrefix() {
        cntPrefix--;
    }
    int getPrefix() {
        return cntPrefix;
    }
    int getEnd() {
        return cntEndsWith;
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
        Node *node = root;
        for (auto &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    /*  returns how many times this “word” is present in this "Trie" */
    int countWordsEqualTo(string &word) {

        Node *node = root;
        for (auto &ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->getEnd();
    }

    /* returns how many words are there in this "Trie" that have the string "prefix" as a prefix. */
    int countWordsStartingWith(string &prefix) {
        Node *node = root;
        for (auto &ch : prefix) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    /* delete one occurrence of the string "word" from the "Trie". The word already presents in the Trie */
    void erase(string &word) {
        Node *node = root;
        for (auto &ch : word) {
            if (!node->containsKey(ch)) {
                return;
            }
            node->decreasePrefix();
            node = node->get(ch);
        }
        node->deleteEnd();
    }
};
int main() {

    return 0;
}