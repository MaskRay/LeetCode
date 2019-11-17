// Greatest Sum Divisible by Three
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    int tot = 0, ans = 0, a[2] = {10001, 10001}, b[2] = {10001, 10001};
    for (int x: nums) {
      int k = x%3;
      if (k--) {
        b[k] = min(b[k], x);
        if (b[k] < a[k]) swap(a[k], b[k]);
      }
      tot += x;
    }
    int k = tot%3;
    if (!k--)
      return tot;
    if (a[k] < 10001)
      ans = tot-a[k];
    if (b[k^1] < 10001)
      ans = max(ans, tot-a[k^1]-b[k^1]);
    return ans;
  }
};
