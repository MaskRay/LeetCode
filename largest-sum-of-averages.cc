// Largest Sum of Averages
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  double largestSumOfAverages(vector<int>& a, int k) {
    int n = a.size();
    vector<double> s(n+1), dp(n+1, -INFINITY);
    REP(i, n)
      s[i+1] = s[i]+a[i];
    dp[0] = 0;
    while (k--)
      for (int i = n; i; i--)
        REP(j, i)
          dp[i] = max(dp[i], dp[j]+(s[i]-s[j])/(i-j));
    return dp[n];
  }
};
