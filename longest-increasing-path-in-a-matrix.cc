// Longest Increasing Path in a Matrix
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
  int m, n;
  vector<vector<int>> a, dp;
  int dfs(int i, int j) {
    if (dp[i][j]) return dp[i][j];
    int s = 0;
    if (i && a[i][j] < a[i-1][j]) s = max(s, dfs(i-1, j));
    if (i+1 < m && a[i][j] < a[i+1][j]) s = max(s, dfs(i+1, j));
    if (j && a[i][j] < a[i][j-1]) s = max(s, dfs(i, j-1));
    if (j+1 < n && a[i][j] < a[i][j+1]) s = max(s, dfs(i, j+1));
    return dp[i][j] = s+1;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& a) {
    m = a.size();
    if (! m) return 0;
    n = a[0].size();
    dp.resize(m);
    REP(i, m)
      dp[i].assign(n, 0);
    this->a = a;
    int s = 0;
    REP(i, m)
      REP(j, n)
        if (! dp[i][j])
          s = max(s, dfs(i, j));
    return s;
  }
};
