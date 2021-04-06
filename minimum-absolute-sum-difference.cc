// Minimum Absolute Difference
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> a(nums1);
    sort(ALL(a));
    long n = a.size(), sum = 0;
    REP(i, n) sum += abs(nums1[i]-nums2[i]);
    long ans = sum;
    REP(i, n) {
      auto it = lower_bound(ALL(a), nums2[i]);
      if (it != a.end())
        ans = min(ans, sum-abs(nums1[i]-nums2[i])+*it-nums2[i]);
      if (it != a.begin())
        ans = min(ans, sum-abs(nums1[i]-nums2[i])+nums2[i]-it[-1]);
    }
    return ans%1000000007;
  }
};
