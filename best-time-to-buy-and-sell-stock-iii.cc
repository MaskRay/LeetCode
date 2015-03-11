// Best Time to Buy and Sell Stock III
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int x = 0, y = INT_MIN/2, xx = 0, yy = INT_MIN/2;
    for (auto p: prices) {
      y = max(y, -p);
      x = max(x, y+p);
      yy = max(yy, x-p);
      xx = max(xx, yy+p);
    }
    return xx;
  }
};
