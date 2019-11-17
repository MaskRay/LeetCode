// Minimum Moves to Move a Box to Their Target Location
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int vis[20][20][20];

class Solution {
public:
  int minPushBox(vector<vector<char>>& grid) {
    using pii = pair<int, int>;
    using state = pair<pii, pii>;
    int n = grid.size(), m = grid[0].size();
    pii src, box, tar;
    const int dirs[][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    REP(i, n) REP(j, m)
      switch (grid[i][j]) {
      case 'S': src = {i, j}; break;
      case 'B': box = {i, j}; break;
      case 'T': tar = {i, j}; break;
      }
    memset(vis, 0, sizeof vis);
    deque<state> q;
    q.push_back({src, box});
    vis[src.first][src.second][box.first] = 1 << box.second;
    int d = 0, e = 1;
    while (q.size()) {
      state c = q.front();
      q.pop_front();
      if (e) e--;
      else e = q.size(), d++;
      for (auto dir: dirs) {
        unsigned x = c.first.first+dir[0], y = c.first.second+dir[1];
        if (x >= n || y >= m || grid[x][y] == '#') continue;
        state s;
        int cost = 0;
        if (pii(x, y) == c.second) {
          unsigned xx = x+dir[0], yy = y+dir[1];
          if (xx >= n || yy >= m || grid[xx][yy] == '#') continue;
          if (pii(xx, yy) == tar) return d+1;
          s = {{x, y}, {xx, yy}};
          cost = 1;
        } else
          s = {{x, y}, c.second};
        int &v = vis[x][y][s.second.first];
        if (!(v & 1 << s.second.second)) {
          v |= 1 << s.second.second;
          if (cost) q.push_back(s);
          else e++, q.push_front(s);
        }
      }
    }
    return -1;
  }
};
