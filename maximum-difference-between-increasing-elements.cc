// Maximum Difference Between Increasing Elements
class Solution {
public:
  int maximumDifference(vector<int>& nums) {
    int mn = 1e9, ans = -1;
    for (int x: nums) {
      if (x > mn)
        ans = max(ans, x-mn);
      mn = min(mn, x);
    }
    return ans;
  }
};
