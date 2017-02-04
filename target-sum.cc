// Target Sum
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int b = accumulate(ALL(nums), 0);
    if (S < -b || b < S)
      return 0;
    vector<int> a(2*b+1), c(2*b+1);
    a[b] = 1;
    for (auto x: nums) {
      fill(ALL(c), 0);
      REP(i, 2*b+1)
        if (a[i]) {
          c[i-x] += a[i];
          c[i+x] += a[i];
        }
      a.swap(c);
    }
    return a[b+S];
  }
};
