// Verifying an Alien Dictionary
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<char> x(127);
    int n = order.size();
    REP(i, n)
      x[order[i]] = i;
    for (auto &w : words)
      for (auto &c : w)
        c = x[c];
    FOR(i, 1, words.size())
      if (words[i-1] > words[i])
        return false;
    return true;
  }
};
