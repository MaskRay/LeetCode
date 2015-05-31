// Add and Search Word - Data structure design
class WordDictionary {
public:
  class TrieNode {
  public:
    // Initialize your data structure here.
    bool has;
    TrieNode *c[26];
    TrieNode() : has(false) {
      fill_n(c, 26, nullptr);
    }
  } *root;

  WordDictionary() : root(new TrieNode) {}

  // Adds a word into the data structure.
  void addWord(string word) {
    auto x = root;
    for (auto c: word) {
      if (! x->c[c-'a'])
        x->c[c-'a'] = new TrieNode;
      x = x->c[c-'a'];
    }
    x->has = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return search(word, 0, root);
  }

  bool search(const string &word, string::size_type i, TrieNode *x) {
    for (; i < word.size(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++)
          if (x->c[j] && search(word, i+1, x->c[j]))
            return true;
        return false;
      }
      if (! x->c[word[i]-'a'])
        return false;
      x = x->c[word[i]-'a'];
    }
    return x->has;
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
