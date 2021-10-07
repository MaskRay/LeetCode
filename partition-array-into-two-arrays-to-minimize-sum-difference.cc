#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int minimumDifference(vector<int>& a) {
    int n2 = a.size(), n = a.size()/2, sum = accumulate(ALL(a), 0), sum2 = sum/2;
    vector<vector<int>> ls(n+1), rs(n+1);
    REP(k, 1<<n) {
      int s = 0;
      REP(i, n) if (k>>i & 1) s += a[i];
      ls[__builtin_popcount(k)].push_back(s);

      s = 0;
      REP(i, n) if (k>>i & 1) s += a[n+i];
      rs[__builtin_popcount(k)].push_back(s);
    }
    for (auto &l: ls) {
      sort(ALL(l));
      l.erase(unique(ALL(l)), l.end());
    }
    for (auto &r: rs) {
      sort(ALL(r));
      r.erase(unique(ALL(r)), r.end());
    }

    int ans = INT_MAX;
    REP(i, n+1) {
      for (int l: ls[i]) {
        auto it = lower_bound(ALL(rs[n-i]), sum2-l);
        if (it != rs[n-i].end())
          ans = min(ans, abs(2*(l+*it)-sum));
        if (it != rs[n-i].begin())
          ans = min(ans, sum-2*(l+it[-1]));
      }
    }
    return ans;
  }
};
