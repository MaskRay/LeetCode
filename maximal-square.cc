// Maximal Square
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maximalSquare(vector<vector<char>> &a) {
    if (a.empty()) return 0;
    int m = a.size(), n = a[0].size(), ans = 0;
    vector<int> s(n, 0);
    REP(i, m) {
      int ul = 0;
      REP(j, n) {
        int t = ul;
        ul = s[j];
        s[j] = a[i][j] == '1' ? min(min(t, j?s[j-1]:0), s[j])+1 : 0;
        ans = max(ans, s[j]);
      }
    }
    return ans*ans;
  }
};
