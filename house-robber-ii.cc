// House Robber II
class Solution {
public:
  int rob(vector<int>& a) {
    int n = (int)a.size(), t, x = 0, y = 0;
    if (n == 1) return a[0];
    for (int i = 0; i < n-1; i++)
      t = x, x = max(x, y+a[i]), y = t;
    int r = x;
    x = y = 0;
    for (int i = 1; i < n; i++)
      t = x, x = max(x, y+a[i]), y = t;
    return max(r, x);
  }
};
