// Projection Area of 3D Shapes
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int ans = 0;
    for (auto &r: grid)
      ans += r.size()-count(ALL(r), 0) + *max_element(ALL(r));
    REP(j, grid[0].size()) {
      int t = 0;
      REP(i, grid.size())
        t = max(t, grid[i][j]);
      ans += t;
    }
    return ans;
  }
};
