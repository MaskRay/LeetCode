// 采购方案
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int purchasePlans(vector<int>& nums, int target) {
    sort(ALL(nums));
    long n = nums.size(), ans = 0;
    REP(i, n) {
      int j = upper_bound(ALL(nums), target-nums[i]) - nums.begin();
      if (i < j)
        ans += j-i-1;
    }
    return ans%1000000007;
  }
};
