// Bomb Enemy
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, r = 0, row, col[n];
    REP(i, m)
      REP(j, n) {
        if (! j || grid[i][j-1] == 'W') {
          row = 0;
          for (int k = j; k < n && grid[i][k] != 'W'; k++)
            row += grid[i][k] == 'E';
        }
        if (! i || grid[i-1][j] == 'W') {
          col[j] = 0;
          for (int k = i; k < m && grid[k][j] != 'W'; k++)
            col[j] += grid[k][j] == 'E';
        }
        if (grid[i][j] == '0')
          r = max(r, row+col[j]);
      }
    return r;
  }
};
