// Maximum Product Subarray
class Solution {
public:
  int maxProduct(vector<int> &a) {
    int ans = a[0], mi = a[0], ma = a[0];
    for (int i = 1; i < a.size(); i++) {
      int x = mi*a[i], y = ma*a[i];
      mi = min(a[i], min(x, y));
      ma = max(a[i], max(x, y));
      ans = max(ans, ma);
    }
    return ans;
  }
};
