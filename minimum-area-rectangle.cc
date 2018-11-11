// Minimum Area Rectangle
class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    unordered_set<int> s;
    int mx = 40001*40001, r = mx;
    for (auto &ps : points)
      s.insert(ps[0]*40001+ps[1]);
    for (auto &ps : points) {
      int x0 = ps[0], y0 = ps[1];
      for (auto &qs : points) {
        int x1 = qs[0], y1 = qs[1];
        if (x0 != x1 && y0 != y1) {
          if (s.count(x0*40001+y1) && s.count(x1*40001+y0))
            r = min(r, abs(x0-x1)*abs(y0-y1));
        }
      }
    }
    return r == mx ? 0 : r;
  }
};
