#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  vector<int> maximumBobPoints(int num, vector<int>& a) {
    const int N = 12;
    vector<vector<int>> dp(N, vector<int>(num+1));
    vector<int> b(N);
    FOR(i, 1, N) {
      REP(j, a[i]+1)
        dp[i][j] = dp[i-1][j];
      ROF(j, a[i]+1, num+1)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]-1]+i);
    }
    ROF(i, 1, N)
      if (dp[i][num] != dp[i-1][num])
        num -= a[i]+1, b[i] = a[i]+1;
    b[0] = num;
    return b;
  }
};
