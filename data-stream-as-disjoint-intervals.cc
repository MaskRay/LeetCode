// Data Stream as Disjoint Intervals
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
  set<int> s;
public:
  /** Initialize your data structure here. */
  SummaryRanges() {
  }

  void addNum(int val) {
    s.insert(val);
  }

  vector<Interval> getIntervals() {
    vector<Interval> r;
    for (auto i = s.begin(); i != s.end(); ) {
      Interval x(*i, *i);
      auto j = i++;
      while (i != s.end() && *j + 1 == *i) {
        x.end = *i++;
        ++j;
      }
      r.push_back(x);
    }
    return r;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
