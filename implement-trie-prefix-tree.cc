// Implement Trie (Prefix Tree)
class TrieNode {
public:
  // Initialize your data structure here.
  bool has;
  TrieNode *c[26];
  TrieNode() : has(false) {
    fill_n(c, 26, nullptr);
  }
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    auto x = root;
    for (auto c: s) {
      if (! x->c[c-'a'])
        x->c[c-'a'] = new TrieNode;
      x = x->c[c-'a'];
    }
    x->has = true;
  }

  // Returns if the word is in the trie.
  bool search(string key) {
    auto x = root;
    for (auto c: key) {
      if (! x->c[c-'a'])
        return false;
      x = x->c[c-'a'];
    }
    return x->has;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    auto x = root;
    for (auto c: prefix) {
      if (! x->c[c-'a'])
        return false;
      x = x->c[c-'a'];
    }
    return true;
  }

private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
