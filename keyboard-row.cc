// Keyboard Row
class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    vector<string> r;
    string a = "qwertyuiop",
           b = "asdfghjkl",
           c = "zxcvbnm";
    int d[127];
    for (auto i: a) d[i] = d[i-32] = 0;
    for (auto i: b) d[i] = d[i-32] = 1;
    for (auto i: c) d[i] = d[i-32] = 2;
    for (auto word: words) {
      int e[3] = {};
      for (auto c: word)
        e[d[c]]++;
      if (*max_element(e, e+3) == word.size())
        r.push_back(word);
    }
    return r;
  }
};
