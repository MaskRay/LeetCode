// Burst Balloons
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if (! n)
      return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    REP(i, n)
      dp[i][i] = (i ? nums[i-1] : 1) * nums[i] * (i+1 < n ? nums[i+1] : 1);
    ROF(i, 0, n-1)
      FOR(j, i+1, n) {
        int opt = -1, optk;
        FOR(k, i, j+1) {
          int t = (k ? dp[i][k-1] : 0) + (k+1 < n ? dp[k+1][j] : 0) + (i ? nums[i-1] : 1) * nums[k] * (j+1 < n ? nums[j+1] : 1);
          if (t > opt)
            opt = t;
        }
        dp[i][j] = opt;
      }
    return dp[0][n-1];
  }
};
