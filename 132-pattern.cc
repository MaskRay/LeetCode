// 132 Pattern
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size(), j;
    vector<int> l(n), mn(n);
    REP(i, n) {
      for (j = i-1; j >= 0 && nums[j] <= nums[i]; j = l[j]);
      l[i] = j;
      mn[i] = min(nums[i], i ? mn[i-1] : INT_MAX);
    }
    REP(i, n)
      if (l[i] > 0 && mn[l[i]-1] < nums[i])
        return true;
    return false;
  }
};
