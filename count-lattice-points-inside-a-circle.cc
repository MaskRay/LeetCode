// Count Lattice Points Inside a Circle
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
using pii = pair<int, int>;

class Solution {
public:
  int countLatticePoints(vector<vector<int>>& circles) {
    const int R = 100;
    vector<vector<pii>> as(3*R+1);
    for (auto &cir: circles) {
      int x0 = cir[0], y0 = cir[1], r = cir[2];
      FOR(x, x0-r, x0+r+1) {
        int s = r*r-(x-x0)*(x-x0), d = sqrt(s+1e-6);
        as[x+R].emplace_back(y0-d, 1);
        as[x+R].emplace_back(y0+d+1, -1);
      }
    }
    int ret = 0;
    for (auto &a : as) {
      sort(ALL(a));
      int d = 0, bgn = -R-1;
      for (auto &x: a) {
        if (d == 0)
          bgn = x.first;
        d += x.second;
        if (d == 0)
          ret += x.first-bgn;
      }
    }
    return ret;
  }
};
