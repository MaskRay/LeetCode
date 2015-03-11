// Minimum Window Substring
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string minWindow(string S, string T) {
    vector<int> a(127);
    int opt = S.size()+1, opti, c = 0;
    for (auto i: T)
      a[i]--;
    REP(i, 127)
      if (! a[i])
        a[i] = S.size();
      else
        c++;
    for (int i = 0, j = 0; i < S.size(); i++) {
      for (; j < S.size() && c; j++)
        if (!++a[S[j]])
          c--;
      if (c) break;
      if (j-i < opt) {
        opt = j-i;
        opti = i;
      }
      if (!a[S[i]]--)
        c++;
    }
    return opt > S.size() ? "" : S.substr(opti, opt);
  }
};
