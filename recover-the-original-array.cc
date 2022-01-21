#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> recoverArray(vector<int>& a) {
    sort(ALL(a));
    int n = a.size();
    vector<char> used(n);
    auto recover = [&](int d) {
      vector<int> res;
      int j = 0;
      REP(i, n) {
        if (used[i]) continue;
        while (j < n && a[j] < a[i]+d) j++;
        if (!(j < n && a[j] == a[i]+d)) break;
        used[j++] = 1;
        res.push_back(a[i]+d/2);
      }
      if (res.size() != n/2) res.clear();
      while (j) used[--j] = 0;
      return res;
    };

    FOR(i, 1, n) {
      int d = a[i]-a[0];
      if (d == 0 || d % 2) continue;
      vector<int> res = recover(d);
      if (res.size())
        return res;
    }
    return {};
  }
};
