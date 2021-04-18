// Bricks Falling When Hit
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  static constexpr int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
  int m, n, num = 0;
public:
  void dfs(vector<vector<int>> &g, int x, int y) {
    g[x][y] = 2;
    num++;
    REP(i, 4) {
      unsigned x1 = x+dx[i], y1 = y+dy[i];
      if (x1 < m && y1 < n && g[x1][y1] == 1)
        dfs(g, x1, y1);
    }
  }
  vector<int> hitBricks(vector<vector<int>> &g, vector<vector<int>> &hits) {
    vector<int> ans(hits.size());
    m = g.size();
    n = g[0].size();
    for (auto &h: hits)
      g[h[0]][h[1]]--;
    REP(i, n)
      if (g[0][i] == 1)
        dfs(g, 0, i);
    for (int i = hits.size(); i--; ) {
      int old = num;
      int x = hits[i][0], y = hits[i][1];
      if (g[x][y]++) continue;
      bool f = !x;
      REP(d, 4) {
        unsigned x1 = x+dx[d], y1 = y+dy[d];
        if (x1 < m && y1 < n && g[x1][y1] == 2)
          f = true;
      }
      if (f) {
        dfs(g, x, y);
        ans[i] = num-old-1;
      }
    }
    return ans;
  }
};
