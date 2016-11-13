// Minimum Number of Arrows to Burst Balloons
class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    int r = 0;
    sort(points.begin(), points.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
      return x.second < y.second;
    });
    for (int i = 0; i < points.size(); ) {
      r++;
      int t = points[i].second;
      while (++i < points.size() && points[i].first <= t);
    }
    return r;
  }
};
