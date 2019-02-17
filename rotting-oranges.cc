// Rotting Oranges
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int orangesRotting(vector<vector<int>>& g) {
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    int m = g.size(), n = g[0].size(), x, y;
    queue<pair<int, int>> q;
    REP(i, m) REP(j, n)
      if (g[i][j] == 2)
        q.emplace(i, j);
    while (q.size()) {
      tie(x, y) = q.front();
      q.pop();
      REP(i, 4) {
        unsigned xx = x+dx[i], yy = y+dy[i];
        if (xx < m && yy < n && g[xx][yy] == 1)
          g[xx][yy] = g[x][y]+1, q.emplace(xx, yy);
      }
    }
    int ans = 0;
    REP(i, m) REP(j, n) {
      if (g[i][j] == 1)
        return -1;
      ans = max(ans, g[i][j]-2);
    }
    return ans;
  }
};
