// Best Time to Buy and Sell Stock with Cooldown
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int f = - prices[0], g = 0, gg = 0;
    FOR(i, 1, prices.size()) {
      int t = gg;
      gg = g;
      g = max(g, f+prices[i]);
      f = max(f, t-prices[i]);
    }
    return g;
  }
};
