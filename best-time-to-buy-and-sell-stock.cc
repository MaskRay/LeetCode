// Best Time to Buy and Sell Stock
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int x = 0, y = INT_MAX/2;
    for (auto p: prices) {
      y = min(y, p);
      x = max(x, p-y);
    }
    return x;
  }
};
