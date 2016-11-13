// Non-overlapping Intervals
class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& a) {
    sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
      return x.end < y.end;
    });
    int r = 0, y = INT_MIN;
    for (auto& x: a)
      if (y <= x.start) {
        y = x.end;
        r++;
      }
    return a.size()-r;
  }
};
