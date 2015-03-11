// Largest Number
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string largestNumber(vector<int> &a) {
    vector<string> b(a.size());
    REP(i, a.size())
      b[i] = to_string(a[i]);
    sort(b.begin(), b.end(), [](const string &x, const string &y) {
      size_t m = x.size(), n = y.size(), i = 0;
      for (; i < m+n; i++) {
        int d = (i < m ? x[i] : y[i-m]) - (i < n ? y[i] : x[i-n]);
        if (d > 0) return true;
        if (d < 0) return false;
      }
      return false;
    });
    if (b[0] == "0")
      return "0";
    string r;
    for (auto &x: b)
      r += x;
    return r;
  }
};
