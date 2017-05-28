// Delete Operation for Two Strings
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minDistance(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> s(2, vector<int>(n+1));
    iota(s[0].begin(), s[0].end(), 0);
    REP(i, m) {
      s[i+1&1][0] = i+1;
      REP(j, n)
        s[i+1&1][j+1] = a[i] == b[j] ? s[i&1][j] : min(s[i+1&1][j], s[i&1][j+1])+1;
    }
    return s[m&1][n];
  }
};
