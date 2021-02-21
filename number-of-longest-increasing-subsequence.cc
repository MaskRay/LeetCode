
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
    int cutOffTree(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size(), r = 0, sx = 0, sy = 0, x, y;
      int d[50][50];
      pair<int, int> q[2500];
      for(;;) {
        int tx = -1, ty = -1;
        REP(i, m) REP(j, n)
          if (g[i][j] > 1 && (tx<0 || g[i][j] < g[tx][ty]))
            tx = i, ty = j;
        if (tx < 0) break;
        REP(i, m)
          fill_n(d[i], n, -1);
        d[sx][sy] = 0;
        q[0] = make_pair(sx, sy);
        for (int l = 0, h = 1; l < h && d[tx][ty] < 0; l++) {
          tie(x, y) = q[l];
          if (x && g[x-1][y] && d[x-1][y] < 0) d[x-1][y] = d[x][y]+1, q[h++] = {x-1, y};
          if (x+1 < m && g[x+1][y] && d[x+1][y] < 0) d[x+1][y] = d[x][y]+1, q[h++] = {x+1, y};
          if (y && g[x][y-1] && d[x][y-1] < 0) d[x][y-1] = d[x][y]+1, q[h++] = {x, y-1};
          if (y+1 < n && g[x][y+1] && d[x][y+1] < 0) d[x][y+1] = d[x][y]+1, q[h++] = {x, y+1};
        }
        if (d[tx][ty] < 0) return -1;
        g[tx][ty] = 1;
        r += d[tx][ty];
        sx = tx, sy = ty;
      }
      return r;
    }
};
