// Generalized Abbreviation
class Solution {
  vector<string> r;
  void f(int i, bool c, const string &word, string w) {
    if (i == word.size())
      r.push_back(w);
    else {
      f(i+1, true, word, w+word[i]);
      if (c)
        for (int j = i; ++j <= word.size(); )
          f(j, false, word, w+to_string(j-i));
    }
  }
public:
  vector<string> generateAbbreviations(string word) {
    f(0, true, word, "");
    return r;
  }
};
