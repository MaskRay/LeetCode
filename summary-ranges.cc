// Summary Ranges
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<string> summaryRanges(vector<int> &a) {
    vector<string> r;
    int s = 0, n = (int)a.size();
    REP(i, n) {
      if (i == n-1 || a[i]+1 != a[i+1]) {
        r.push_back(s == i ? to_string(a[i]) : to_string(a[s])+"->"+to_string(a[i]));
        s = i+1;
      }
    }
    return r;
  }
};
