// Maximum Size Subarray Sum Equals k
class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, len = 0;
    m[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (m.count(sum-k))
        len = max(len, i-m[sum-k]);
      if (! m.count(sum))
        m[sum] = i;
    }
    return len;
  }
};
