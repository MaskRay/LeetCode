// Find Right Interval
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> findRightInterval(vector<Interval>& intervals) {
    vector<int> r;
    vector<pair<int, int>> a;
    REP(i, intervals.size())
      a.emplace_back(intervals[i].start, i);
    sort(a.begin(), a.end());
    for (auto& x: intervals) {
      auto it = lower_bound(a.begin(), a.end(), make_pair(x.end, 0));
      r.push_back(it == a.end() ? -1 : it->second);
    }
    return r;
  }
};
