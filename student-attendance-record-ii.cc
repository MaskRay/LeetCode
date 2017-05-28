// Student Attendance Record II
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  static const int MOD = 1000000007;
public:
  int checkRecord(int n) {
    int dp[2][3] = {}, dp1[2][3];
    dp[0][0] = 1;
    REP(_, n) {
      memset(dp1, 0, sizeof dp1);
      REP(i, 2)
        REP(j, 3) {
          (dp1[i][0] += dp[i][j]) %= MOD;
          if (! i)
            (dp1[i+1][0] += dp[i][j]) %= MOD;
          if (j < 2)
            (dp1[i][j+1] += dp[i][j]) %= MOD;
        }
      memcpy(dp, dp1, sizeof dp1);
    }
    int r = 0;
    REP(i, 2)
      REP(j, 3)
        (r += dp[i][j]) %= MOD;
    return r;
  }
};
