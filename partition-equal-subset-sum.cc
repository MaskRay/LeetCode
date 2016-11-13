// Partition Equal Subset Sum
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    vector<char> a(s/2+1);
    a[0] = 1;
    for (int x: nums)
      for (int i = a.size(); --i >= x; )
        a[i] |= a[i-x];
    return s%2 == 0 && a[s/2];
  }
};
