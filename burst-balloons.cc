// Burst Balloons
// dynamic programming
// NB. F. Frances Yao's optimization does not apply
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
    ROF(i, 0, n)
      FOR(j, i, n) {
        FOR(k, i, j+1)
          dp[i][j] = max(dp[i][j], (k ? dp[i][k-1] : 0) + (k+1 < n ? dp[k+1][j] : 0) + (i ? nums[i-1] : 1) * nums[k] * (j+1 < n ? nums[j+1] : 1));
      }
    return dp[0][n-1];
  }
};

/// with padding

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    ROF(i, 1, n+1)
      FOR(j, i, n+1)
        FOR(k, i, j+1)
          dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
    return dp[1][n];
  }
};
