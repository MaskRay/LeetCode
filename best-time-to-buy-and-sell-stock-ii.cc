class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int x = 0, y = INT_MIN/2;
    for (auto p: prices) {
      y = max(y, x-p);
      x = max(x, y+p);
    }
    return x;
  }
};
