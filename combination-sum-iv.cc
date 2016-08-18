// Combination Sum IV
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> a(target+1, 0);
    a[0] = 1;
    for (int i = 0; i < target; i++)
      for (int x: nums)
        if (i+x <= target)
          a[i+x] += a[i];
    return a[target];
  }
};
