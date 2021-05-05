#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), m = queries.size();
    REP(i, m) queries[i].push_back(i);
    sort(ALL(nums));
    sort(ALL(queries), [](auto &l, auto &r) { return l[1] < r[1]; });
    vector<int> ans(m), best(m, -1), p0(n), p1(n);
    REP(i, n)
      p0[i] = i-1;
    for (int k = 1<<29; k; k >>= 1) {
      REP(i, n)
        if (p0[i] == -1)
          p1[i] = -1;
        else if (((nums[i]^nums[p0[i]]) & k) == 0)
          p1[i] = p1[p0[i]];
        else
          p1[i] = p0[i], p0[i] = p1[p0[i]];
      int i = 0;
      REP(j, m) {
        for (; i < n && nums[i] <= queries[j][1]; i++);
        int &b = best[j];
        if (b == -1)
          b = i-1;
        if (~b && ((queries[j][0]^nums[b]) & k) == 0 && ~p1[b])
          b = p1[b];
      }
    }
    REP(j, m)
      ans[queries[j][2]] = ~best[j] ? queries[j][0] ^ nums[best[j]] : -1;
    return ans;
  }
};
