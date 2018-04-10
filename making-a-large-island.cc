// Making A Large Island
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  vector<int> uf;
  int f(int x) {
    while (uf[x] > 0)
      uf[x] = uf[uf[x]] > 0 ? uf[uf[x]] : uf[x], x = uf[x];
    return x;
  }
public:
  int largestIsland(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    uf.assign(m*n+1, 0);
    REP(i, m)
      REP(j, n)
        if (g[i][j]) {
          int x = -1, y;
          if (j && g[i][j-1]) {
            x = f(i*n+j);
            uf[x]--;
          } else
            x = -1;
          uf[i*n+j+1] = x;
          if (i && g[i-1][j]) {
            x = f(i*n+j+1);
            y = f((i-1)*n+j+1);
            if (x != y) {
              uf[y] += uf[x];
              uf[x] = y;
            }
          }
        }
    int r = 0;
    REP(i, m)
      REP(j, n) {
        r = max(r, -uf[i*n+j+1]);
        if (!g[i][j]) {
          int cs[4] = {};
          if (i) cs[0] = f((i-1)*n+j+1);
          if (i+1 < m) cs[1] = f((i+1)*n+j+1);
          if (j) cs[2] = f(i*n+j);
          if (j+1 < n) cs[3] = f(i*n+j+2);
          sort(cs, cs+4);
          int k = unique(cs, cs+4) - cs, t = 1;
          while (k--) t -= uf[cs[k]];
          r = max(r, t);
        }
      }
    return r;
  }
};
