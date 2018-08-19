// Find and Replace Pattern
class Solution {
  string f(string p) {
    int x[26], i =0;
    fill_n(x, 26, -1);
    for (char &c : p) {
      if (x[c -= 'a'] < 0)
        x[c] = i++;
      c = x[c];
    }
    return p;
  }

public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> r;
    pattern = f(pattern);
    for (auto &word : words)
      if (f(word) == pattern)
        r.push_back(word);
    return r;
  }
};
