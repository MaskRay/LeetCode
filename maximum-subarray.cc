// Maximum Subarray
// Kadane's algorithm
class Solution {
public:
  int maxSubArray(vector<int> &a) {
    int r = a[0], s = 0;
    for (auto x: a) {
      s = max(s, 0) + x;
      r = max(r, s);
    }
    return r;
  }
};
