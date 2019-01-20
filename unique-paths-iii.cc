// Unique Paths III
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size(), ob=0, s, sink;
    REP(i, m) REP(j, n) {
      if (g[i][j] < 0)
        ob |= 1<<i*n+j;
      else if (g[i][j] == 1)
        s = i*n+j;
      else if (g[i][j] == 2)
        sink = i*n+j;
    }
    vector<vector<short>> v(m*n, vector<short>(1<<m*n));
    v[s][ob|1<<s] = 1;
    for (int i = __builtin_popcount(ob)+1; i < n*m; i++) {
      int g = (1<<i)-1, mx = (1<<i)-1 << n*m-i;
      for(;;) {
        for (int gg = g; gg; gg &= gg-1) {
          int s = __builtin_ctz(gg), vv = v[s][g];
          if (vv) {
            int sx = s/n, sy = s%n;
            if (sx && !(g & 1<<s-n)) v[s-n][g|1<<s-n] += vv;
            if (sx+1<m && !(g & 1<<s+n)) v[s+n][g|1<<s+n] += vv;
            if (sy && !(g & 1<<s-1)) v[s-1][g|1<<s-1] += vv;
            if (sy+1<n && !(g & 1<<s+1)) v[s+1][g|1<<s+1] += vv;
          }
        }
        if (g == mx) break;
        int h = (g | g-1) + 1;
        g = h | (h&-h)-1 >> __builtin_ctz(g)+1;
      }
    }
    return v[sink][(1<<n*m)-1];
  }
};

///


#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size(), ob=0, s, k, sink;
    REP(i, m) REP(j, n) {
      if (g[i][j] < 0)
        ob |= 1<<i*n+j;
      else if (g[i][j] == 1)
        s= i*n+j;
      else if (g[i][j] == 2)
        sink = i*n+j;
    }
    vector<vector<short>> v(m*n, vector<short>(1<<m*n));
    vector<pair<int, int>> cur, suc;
    cur.emplace_back(s, ob|1<<s);
    v[s][ob|1<<s] = 1;
    while (cur.size()) {
      suc.clear();
      for (auto x : cur) {
        tie(s, k) = x;
        int sx = s/n, sy = s%n, vv = v[s][k];
        if (sx && !(k & 1<<s-n) && (v[s-n][k|1<<s-n]+=vv)==vv) suc.emplace_back(s-n, k|1<<s-n);
        if (sx+1<m && !(k & 1<<s+n) && (v[s+n][k|1<<s+n]+=vv)==vv) suc.emplace_back(s+n, k|1<<s+n);
        if (sy && !(k & 1<<s-1) && (v[s-1][k|1<<s-1]+=vv)==vv) suc.emplace_back(s-1, k|1<<s-1);
        if (sy+1<n && !(k & 1<<s+1) && (v[s+1][k|1<<s+1]+=vv)==vv) suc.emplace_back(s+1, k|1<<s+1);
      }
      cur.swap(suc);
    }
    return v[sink][(1<<n*m)-1];
  }
};
