// Earliest Possible Day of Full Bloom
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int earliestFullBloom(vector<int>& a, vector<int>& b) {
    int n = a.size(), s = 0, ret = 0;
    vector<pair<int, int>> p(n);
    REP(i, n)
      p[i] = {a[i], b[i]};
    sort(ALL(p), [](auto &x, auto &y) {
      return x.second > y.second;
    });
    for (auto x: p) {
      s += x.first;
      ret = max(ret, s+x.second);
    }
    return ret;
  }
};
