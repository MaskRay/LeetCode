// Matchsticks to Square
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool makesquare(vector<int>& a) {
    if (a.empty()) return false;
    int n = a.size(), s = accumulate(a.begin(), a.end(), 0);
    vector<char> g(1<<n);
    if (s%4 == 0) {
      s /= 4;
      REP(i, 1<<n) {
        int t = 0;
        REP(j, n)
          if (i>>j&1)
            t += a[j];
        if (t == s)
          g[i] = 1;
      }
      REP(i, 1<<n)
        if (! g[i]) {
          int t = 0;
          REP(j, n)
            if (i>>j&1)
              t += a[j];
          if (t%s == 0)
            for (int j = i; ; j = j-1 & i) {
              if (g[j] && g[i-j]) {
                g[i] = 1;
                break;
              }
              if (! j) break;
            }
        }
      return g.back();
    }
    return false;
  }
};
