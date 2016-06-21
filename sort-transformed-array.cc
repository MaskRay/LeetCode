// Sort Transformed Array
class Solution {
public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
#define S(x, y) ((x) < (y) ? 1 : (x) > (y) ? 2 : 0)
    if (nums.empty())
      return nums;
    for (auto& x: nums)
      x = (x*a+b)*x+c;
    int i = 1, dir = S(nums[0], nums[1]);
    while (i < nums.size() && (dir |= S(nums[i-1], nums[i])) != 3)
      i++;
    if (i >= 2 && nums[0] > nums[i-1])
      reverse(nums.begin(), nums.begin()+i);
    if (i+2 <= nums.size() && nums[i] > nums.back())
      reverse(nums.begin()+i, nums.end());
    vector<int> r;
    merge(nums.begin(), nums.begin()+i, nums.begin()+i, nums.end(), back_inserter(r));
    return r;
  }
};
