// Find the Duplicate Number
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int r = 0;
    for (int b = 1; b < nums.size(); b <<= 1) {
      int c = 0;
      for (int i = 0; i < nums.size(); i++)
        c += !!(nums[i]&b)-!!(i&b);
      if (c)
        r |= b;
    }
    return r;
  }
};
