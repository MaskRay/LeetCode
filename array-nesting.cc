// Array Nesting
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int n = nums.size(), r = 0;
    vector<int> v(n, 0);
    REP(i, nums.size())
      if (! v[i]) {
        int c = 0;
        for (int j = i; ; ) {
          c++;
          v[j] = 1;
          j = nums[j];
          if (j == i) break;
        }
        r = max(r, c);
      }
    return r;
  }
};
