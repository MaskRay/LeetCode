// Convex Polygon
class Solution {
public:
  bool isConvex(vector<vector<int>>& points) {
    if (points.size() < 3) return false;
    int f = -1;
    for (int i = 0; i < points.size(); i++) {
      auto pre = i == 0 ? points.back() : points[i - 1], post = i == points.size() - 1 ? points[0] : points[i + 1];
      int t = (points[i][0]-pre[0])*(post[1]-points[i][1]) - (post[0]-points[i][0])*(points[i][1]-pre[1]);
      if (f == -1) {
        if (t) f = t > 0;
      } else if (f != t > 0)
        return false;
    }
    return true;
  }
};
