// Regions Cut By Slashes
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int regionsBySlashes(vector<string> &g) {
    int n = g.size();
    vector<int> uf(n*n*4);
    iota(ALL(uf), 0);
    auto f = [&](int x) {
      while (uf[x] != x)
        uf[x] = uf[uf[x]], x = uf[x];
      return x;
    };
    auto me = [&](int x, int y) { uf[f(x)] = f(y); };
    REP(i, n) REP(j, n) {
      int t = (i*n+j)*4;
      switch (g[i][j]) {
      case '/': me(t+0, t+1); me(t+2, t+3); break;
      case '\\': me(t+0, t+3); me(t+1, t+2); break;
      default: me(t+0, t+1); me(t+1, t+2); me(t+2, t+3); break;
      }
      if (i) me(t+0, t-4*n+2);
      if (j) me(t+1, t-4+3);
    }
    int r = 0;
    REP(i, n*n*4) r += uf[i] == i;
    return r;
  }
};
