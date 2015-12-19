// Shortest Distance from All Buildings
typedef pair<int, int> pii;
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int shortestDistance(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = INT_MAX;
    vector<vector<int>> ds(m, vector<int>(n, 0)), d(m, vector<int>(n));
    REP(i, m)
      REP(j, n)
        if (grid[i][j] == 1) {
          queue<pii> q;
          q.emplace(i, j);
          REP(ii, m)
            fill_n(d[ii].begin(), n, -1);
          d[i][j] = 0;
          while (! q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if (! grid[x][y] || x == i && y == j)
              REP(k, 4) {
                int xx = x+((int[]){-1,0,1,0})[k], yy = y+((int[]){0,1,0,-1})[k];
                if (unsigned(xx) < m && unsigned(yy) < n && d[xx][yy] < 0) {
                  d[xx][yy] = d[x][y]+1;
                  q.emplace(xx, yy);
                }
              }
          }
          REP(ii, m)
            REP(jj, n)
              ds[ii][jj] = ds[ii][jj] < 0 || d[ii][jj] < 0 ? -1 : ds[ii][jj]+d[ii][jj];
        }
    REP(i, m)
      REP(j, n)
        if (! grid[i][j] && ds[i][j] >= 0)
          ans = min(ans, ds[i][j]);
    return ans == INT_MAX ? -1 : ans;
  }
};
