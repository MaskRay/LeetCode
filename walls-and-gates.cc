// Walls and Gates
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &a) {
    int n = a.size();
    if (! n) return;
    int m = a[0].size();
    queue<pair<int, int>> q;
    REP(i, n)
      REP(j, m)
        if (! a[i][j])
          q.push({i, j});
    while (! q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      REP(d, 4) {
        int xx = ((int[]){-1,0,1,0})[d]+x,
            yy = ((int[]){0,1,0,-1})[d]+y;
        if (unsigned(xx) < n && unsigned(yy) < m && a[xx][yy] == 2147483647) {
          a[xx][yy] = a[x][y]+1;
          q.push({xx, yy});
        }
      }
    }
  }
};
