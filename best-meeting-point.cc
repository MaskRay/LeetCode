// Best Meeting Point
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> xs, ys;
    REP(i, grid.size())
      REP(j, grid[0].size())
      if (grid[i][j]) {
        xs.push_back(i);
        ys.push_back(j);
      }
    nth_element(ys.begin(), ys.begin()+ys.size()/2, ys.end());
    int d = 0, rx = xs[xs.size()/2], ry = ys[ys.size()/2];
    for (auto x: xs)
      d += abs(x - rx);
    for (auto y: ys)
      d += abs(y - ry);
    return d;
  }
};
