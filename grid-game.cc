// Grid Game
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    long n = grid[0].size(), ans = LONG_MAX;
    vector<long> l(n), r(n+1);
    REP(i, n)
      l[i] = grid[1][i] + (i ? l[i-1] : 0);
    ROF(i, 0, n)
      r[i] = grid[0][i] + r[i+1];
    REP(i, n)
      ans = min(ans, max(r[i+1], i ? l[i-1] : 0));
    return ans;
  }
};
