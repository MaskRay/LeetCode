// Shift 2D Grid
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size(), g = 0;
    vector<int> a(n*m);
    REP(i, n) REP(j, m)
      a[g++] = grid[i][j];
    rotate(a.begin(), a.end()-k%(n*m), a.end());
    g = 0;
    REP(i, n) REP(j, m)
      grid[i][j] = a[g++];
    return grid;
  }
};
