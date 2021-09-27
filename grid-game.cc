// Grid Game
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    long n = grid[0].size(), ans = LONG_MAX;
    vector<long> l(n), r(n+1);
    REP(i, n)
      l[i] = grid[1][i] + (i ? l[i-1] : 0);
    ROF(i, 0, n)
      r[i] = grid[0][i] + (i+1<n ? r[i+1] : 0);
    REP(i, n)
      ans = min(ans, max(r[i+1], i ? l[i-1] : 0));
    return ans;
  }
};
