#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minDistance(string a, string b) {
    vector<vector<int>> f(2, vector<int>(b.size()+1));
    iota(f[0].begin(), f[0].end(), 0);
    REP(i, a.size()) {
      f[i+1&1][0] = i+1;
      REP(j, b.size())
        f[i+1&1][j+1] = a[i] == b[j] ? f[i&1][j] : min(min(f[i&1][j], f[i&1][j+1]), f[i+1&1][j]) + 1;
    }
    return f[a.size()&1][b.size()];
  }
};
