// Longest Increasing Path in a Matrix
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  vector<vector<int>> a, dp;
  int dfs(int i, int j) {
    if (dp[i][j]) return dp[i][j];
    int s = 0;
    REP(d, 4) {
      unsigned i1 = i+((int []){-1,0,1,0})[d], j1 = j+((int []){0,1,0,-1})[d];
      if (i1 < a.size() && j1 < a[0].size() && a[i][j] < a[i1][j1])
        s = max(s, dfs(i1, j1));
    }
    return dp[i][j] = s+1;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& a) {
    dp.assign(a.size(), vector(a[0].size(), 0));
    this->a = a;
    int s = 0;
    REP(i, a.size())
      REP(j, a[0].size())
        s = max(s, dfs(i, j));
    return s;
  }
};
