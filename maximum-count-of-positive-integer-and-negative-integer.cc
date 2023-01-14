// Maximum Count of Positive Integer and Negative Integer
class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int a = 0, b = 0;
    for (int x : nums)
      a += x > 0, b += x < 0;
    return max(a, b);
  }
};
