#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int minCut(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n));
    vector<int> g(n+1);
    g[n] = 0;
    ROF(i, 0, n) {
      f[i][i] = true;
      if (i+1 < n)
        f[i][i+1] = s[i] == s[i+1];
      FOR(j, i+2, n)
        if (f[i+1][j-1] && s[i] == s[j])
          f[i][j] = true;
      g[i] = n;
      FOR(j, i, n)
        if (f[i][j])
          g[i] = min(g[i], g[j+1]+1);
    }
    return g[0]-1;
  }
};

