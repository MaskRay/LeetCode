// Line Reflection
class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
      return x.second != y.second ? x.second < y.second : x.first < y.first;
    });
    long r = LONG_MIN;
    for (auto i = points.begin(); i != points.end(); ) {
      auto j = i;
      while (++i != points.end() && j->second == i->second);
      for (auto jj = j, ii = i; points.begin() < ii && jj <= --ii; ++jj) {
        if (r != LONG_MIN && r != jj->first + ii->first)
          return false;
        r = jj->first + ii->first;
      }
    }
    return true;
  }
};
