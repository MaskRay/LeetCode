// Optimal Account Balancing
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minTransfers(vector<vector<int>>& t) {
    unordered_map<int, int> m;
    int r = 0, c = 0;
    for (auto& x: t) {
      m[x[0]] += x[2];
      m[x[1]] -= x[2];
    }
    vector<int> a;
    for (auto& x: m)
      if (x.second)
        a.push_back(x.second);
    if (a.empty()) return 0;
    vector<int> dp(1<<a.size(), INT_MAX/2), cir;
    FOR(i, 1, 1<<a.size()) {
      int t = 0, c = 0;
      REP(j, a.size())
        if (i>>j & 1)
          t += a[j], c++;
      if (! t) {
        dp[i] = c-1;
        for (int t: cir)
          if ((i & t) == t)
            dp[i] = min(dp[i], dp[t]+dp[i-t]);
        cir.push_back(i);
      }
    }
    return dp.back();
  }
};
