// 变换的迷宫
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

char dp[50][50][6], dp1[50][50][6];

class Solution {
public:
  bool escapeMaze(vector<vector<string>>& a) {
    const int dx[] = {0,-1,0,1,0};
    const int dy[] = {0,0,-1,0,1};
    int m = a[0].size(), n = a[0][0].size();
    // i%2==0: no temp, i%2==1: has temp
    // i/2==0: cannot stay, i/2==1: staying, i/2==2: can stay
    memset(dp, 0, sizeof dp);
    dp[0][0][5] = 1;
    FOR(ai, 1, a.size()) {
      auto &g = a[ai];
      memset(dp1, 0, sizeof dp1);
      REP(x, m) REP(y, n) REP(i, 6)
        if (dp[x][y][i])
          REP(d, 5) {
            unsigned x1 = x+dx[d], y1 = y+dy[d];
            if (x1 >= m || y1 >= n) continue;
            if (g[x1][y1] == '.' || !d && i&2)
              dp1[x1][y1][d ? i&~2 : i] = 1;
            else {
              if (i & 1)
                dp1[x1][y1][(d ? i&~2 : i) & ~1] = 1;
              if (i & 4)
                dp1[x1][y1][i-2] = 1;
            }
          }
      memcpy(dp, dp1, sizeof dp);
    }
    return accumulate(dp[m-1][n-1], dp[m-1][n-1]+6, 0);
  }
};
