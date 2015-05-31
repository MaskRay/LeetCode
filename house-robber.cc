// House Robber
class Solution {
public:
  int rob(vector<int> &a) {
    int x = 0, y = 0;
    for (auto i: a) {
      int yy = y;
      y = max(y, x);
      x = max(x, yy+i);
    }
    return x;
  }
};
