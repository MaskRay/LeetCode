// Longest Common Prefix
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    int r = 0;
    for(;;) {
      char c = strs[0][r];
      REP(i, strs.size())
        if (! strs[i][r] || strs[i][r] != c)
          return strs[0].substr(0, r);
      r++;
    }
  }
};
