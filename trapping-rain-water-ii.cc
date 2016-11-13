// Trapping Rain Water II
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int trapRainWater(vector<vector<int>>& h) {
    if (h.size() < 3 || h[0].size() < 3) return 0;
    int r = 0, m = h.size(), n = h[0].size(), x, y;
    vector<vector<char>> v(m, vector<char>(n, 0));
    vector<vector<pair<int, int>>> s(20001);
    REP(i, m) {
      s[h[i][0]].emplace_back(i, 0);
      s[h[i][n-1]].emplace_back(i, n-1);
      v[i][0] = v[i][n-1] = 1;
    }
    FOR(i, 1, n) {
      s[h[0][i]].emplace_back(0, i);
      s[h[m-1][i]].emplace_back(m-1, i);
      v[0][i] = v[m-1][i] = 1;
    }
    REP(i, s.size())
      while (s[i].size()) {
        tie(x, y) = s[i].back();
        s[i].pop_back();
        REP(d, 4) {
          int xx = x+((int[]){-1,0,1,0})[d], yy = y+((int[]){0,1,0,-1})[d];
          if (unsigned(xx) < m && unsigned(yy) < n && ! v[xx][yy]) {
            v[xx][yy] = 1;
            int t = max(h[x][y], h[xx][yy]);
            r += t-h[xx][yy];
            h[xx][yy] = t;
            s[t].emplace_back(xx, yy);
          }
        }
      }
    return r;
  }
};
