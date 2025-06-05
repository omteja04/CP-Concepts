/**
 * Author: omteja04
 * Created on: 08-02-2025 11:02:12
 * Description: WordBreak2
 **/
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
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
    void insert(string str) {
        Node *node = root;
        for(char ch: str) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string str) {
        Node *node = root;
        for(char &ch: str) {
            if(!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    Node *getRoot() {
        return root;
    }
};

class Solution {
private:
    unordered_map<int, vector<string>> dp;
    vector<string> dfs(int idx, string &s, Trie &trie) {
        if(dp.count(idx)) {
            return dp[idx];
        }
        if(idx == s.length()) {
            return {""};
        }
        vector<string> res;
        Node *node = trie.getRoot();
        for(int i = idx; i < s.length(); i++) {
            char ch = s[i];
            if(!node->containsKey(ch)) {
                break;
            }
            node = node->get(ch);
            if(node->isEnd()) {
                string word = s.substr(idx, i - idx + 1);
                vector<string> suffixes = dfs(i + 1, s, trie);
                for(const string &suffix: suffixes) {
                    res.push_back(word + (suffix.empty() ? "" : " " + suffix));
                }
            }
        }
        return dp[idx] = res;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        Trie trie;
        for(auto &word: wordDict) {
            trie.insert(word);
        }
        return dfs(0, s, trie);
    }
};
