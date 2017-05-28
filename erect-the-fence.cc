// Erect the Fence
class Solution {
  static int cross(Point o, Point a, Point b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
  }
  static bool cmp(Point a, Point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
  }
  static bool eq(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
  }
public:
  vector<Point> outerTrees(vector<Point>& A) {
    vector<Point> ret;
    int n = A.size();
    if (n <= 1) return A;
    sort(A.begin(), A.end(), cmp);
    for (int i = 0; i < n; ret.push_back(A[i++]))
      while (ret.size() > 1 && cross(ret[ret.size()-2], ret.back(), A[i]) > 0)
        ret.pop_back();
    for (int i = n-2, t = ret.size(); i >= 0; ret.push_back(A[i--]))
      while (ret.size() > t && cross(ret[ret.size()-2], ret.back(), A[i]) > 0)
        ret.pop_back();
    ret.pop_back();
    sort(ret.begin(), ret.end(), cmp);
    ret.erase(unique(ret.begin(), ret.end(), eq), ret.end());
    return ret;
  }
};
