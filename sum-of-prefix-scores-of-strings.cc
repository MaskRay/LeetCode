// Sum of Prefix Scores of Strings
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> sumPrefixScores(vector<string>& ws) {
    int n = ws.size();
    vector<int> h(n), res(n);
    vector<pair<string, int>> a(n);
    REP(i, n)
      a[i] = {ws[i], i};
    sort(ALL(a));
    FOR(i, 1, n) {
      auto &x = a[i-1].first, &y = a[i].first;
      while (h[i] < x.size() && x[h[i]] == y[h[i]])
        h[i]++;
    }
    REP(i, n) {
      int x = INT_MAX, v = a[i].first.size();
      for (int j = i; h[j]; j--) {
        x = min(x, h[j]);
        v += x;
      }
      x = INT_MAX;
      for (int j = i; ++j < n && h[j]; ) {
        x = min(x, h[j]);
        v += x;
      }
      res[a[i].second] = v;
    }
    return res;
  }
};
