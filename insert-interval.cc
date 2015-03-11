// Insert Interval
class Solution {
public:
  vector<Interval> insert(vector<Interval> &xs, Interval x) {
    vector<Interval> r(1, x);
    for (auto &y: xs) {
      x = r.back();
      if (y.end < x.start) {
        r.back() = y;
        r.push_back(x);
      } else if (x.end < y.start)
        r.push_back(y);
      else {
        r.back().start = min(x.start, y.start);
        r.back().end = max(x.end, y.end);
      }
    }
    return r;
  }
};
