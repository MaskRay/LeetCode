// Coin Change
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    for (int x: coins)
      for (int i = x; i <= amount; i++)
        if (dp[i-x] >= 0 && (dp[i] < 0 || dp[i-x]+1 < dp[i]))
          dp[i] = dp[i-x]+1;
    return dp[amount];
  }
};
