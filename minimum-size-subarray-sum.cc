// Minimum Size Subarray Sum
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& a) {
    int n = (int)a.size(), c = n+1;
    for (int i = 0, j = 0; i < n; i++) {
      for (; j < n && s > 0; j++)
        s -= a[j];
      if (s > 0) break;
      c = min(c, j-i);
      s += a[i];
    }
    return c > n ? 0 : c;
  }
};
