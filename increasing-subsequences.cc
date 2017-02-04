// Increasing Subsequences
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> r;
    REP(i, 1<<n) {
      int last = -1000;
      vector<int> a;
      REP(j, n)
        if (i>>j&1) {
          if (last > nums[j])
            goto out;
          a.push_back(last = nums[j]);
        }
      if (a.size() > 1)
        r.push_back(a);
out:;
    }
    sort(ALL(r));
    r.erase(unique(ALL(r)), r.end());
    return r;
  }
};
