// Max Consecutive Ones
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int r = 0;
    for (int i = 0; i < nums.size(); )
      if (nums[i] != 1)
        i++;
      else {
        int j = i;
        while (++j < nums.size() && nums[j] == 1);
        r = max(r, j-i);
      }
    return r;
  }
};
