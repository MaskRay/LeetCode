// Minimum Cost to Make at Least One Valid Path in a Grid
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  static constexpr int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
  int minCost(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size(), ret = 0, fore = 0;
    vector<vector<int>> d(m, vector<int>(n, -1));
    vector<pair<int, int>> q;
    auto flood = [&](unsigned x, unsigned y) {
      while (x < m && y < n && d[x][y] == -1) {
        d[x][y] = ret;
        q.emplace_back(x, y);
        const int *next = dir[g[x][y]-1];
        x += next[0];
        y += next[1];
      }
    };
    flood(0, 0);
    while (d[m-1][n-1] == -1) {
      ret++;
      for (int x, y, rear = q.size(); fore != rear; ) {
        tie(x, y) = q[fore++];
        REP(i, 4)
          flood(x+dir[i][0], y+dir[i][1]);
      }
    }
    return d[m-1][n-1];
  }
};
