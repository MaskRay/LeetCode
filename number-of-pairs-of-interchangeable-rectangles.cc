// Number of Pairs of Interchangeable Rectangles
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rs) {
    auto a = rs;
    for (auto &x: a) {
      long d = __gcd(x[0], x[1]);
      x[0] /= d;
      x[1] /= d;
    }
    sort(ALL(a));
    long ans = 0;
    for (long j = 0, i = 0; i != a.size(); i = j) {
      for (; j < a.size() && a[i] == a[j]; j++);
      ans += (j-i)*(j-i-1)/2;
    }
    return ans;
  }
};
