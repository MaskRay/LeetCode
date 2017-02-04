// The Maze
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    const int dx[] = {1,0,0,-1}, dy[] = {0,-1,1,0};
    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> d(m, vector<int>(n, INT_MAX));
    vector<vector<string>> p(m, vector<string>(n));
    vector<vector<char>> v(m, vector<char>(n, 0));
    d[ball[0]][ball[1]] = 0;
    for(;;) {
      int mind = INT_MAX, x0 = -1, y0 = -1;
      REP(i, m)
        REP(j, n)
          if (d[i][j] < mind && !v[i][j])
            mind = d[i][j], x0 = i, y0 = j;
      if (x0 < 0) return "impossible";
      if (x0 == hole[0] && y0 == hole[1])
        return p[x0][y0];
      v[x0][y0] = 1;
      REP(i, 4) {
        int x = x0, y = y0, x1, y1, l = 0;
        for(;;) {
          x1 = x+dx[i];
          y1 = y+dy[i];
          char ok = 1;
          if (x1 == hole[0] && y1 == hole[1]) {
            ok = 0;
            x = x1;
            y = y1;
            l++;
          }
          if (! (ok && unsigned(x1) < m && unsigned(y1) < n && ! maze[x1][y1])) {
            if (mind+l < d[x][y]) {
              d[x][y] = mind+l;
              p[x][y] = "z";
            }
            if (mind+l == d[x][y])
              p[x][y] = min(p[x][y], p[x0][y0]+"dlru"[i]);
            break;
          }
          x = x1;
          y = y1;
          l++;
        }
      }
    }
  }
};
