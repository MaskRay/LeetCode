// Surrounded Regions
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  void solve(vector<vector<char>> &a) {
    if (a.empty() || a[0].empty()) return;
    int m = a.size(), n = a[0].size();
    vector<int> xs, ys;
#define f(x,y) do { \
    a[x][y] = 'Y'; \
    xs.push_back(x); \
    ys.push_back(y); \
  } while (0);
    REP(i, n) {
      if (a[0][i] == 'O') f(0, i);
      if (a[m-1][i] == 'O') f(m-1, i);
    }
    REP(i, m) {
      if (a[i][0] == 'O') f(i, 0);
      if (a[i][n-1] == 'O') f(i, n-1);
    }
    while (! xs.empty()) {
      int x = xs.back(), y = ys.back();
      xs.pop_back();
      ys.pop_back();
      REP(d, 4) {
        int xx = x+(int[]){-1,0,1,0}[d], yy = y+(int[]){0,1,0,-1}[d];
        if (unsigned(xx) < m && unsigned(yy) < n && a[xx][yy] == 'O')
          f(xx, yy);
      }
    }
    REP(i, m)
      REP(j, n)
        if (a[i][j] == 'O') a[i][j] = 'X';
        else if (a[i][j] == 'Y') a[i][j] = 'O';
  }
};
