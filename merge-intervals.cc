// Merge Intervals
class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> r;
    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start < y.start; });
    for (auto &i: intervals)
      if (r.empty() || r.back().end < i.start)
        r.push_back(i);
      else {
        Interval &x = r.back();
        x.start = min(x.start, i.start);
        x.end = max(x.end, i.end);
      }
    return r;
  }
};
