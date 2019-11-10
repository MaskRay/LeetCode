// Number of Closed Islands
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int closedIsland(vector<vector<int>>& a) {
    const int dx[] = {0,-1,0,1};
    const int dy[] = {1,0,-1,0};
    int n = a.size(), m = a[0].size(), x, y, ans = 0;
    vector<pair<int, int>> s;
    REP(i, n) REP(j, m)
      if (!a[i][j]++) {
        int b = 0, x = i, y = j;
        for(;;) {
          REP(d, 4) {
            unsigned xx = x+dx[d], yy = y+dy[d];
            if (xx >= n || yy >= m)
              b = 1;
            else if (!a[xx][yy]++)
              s.emplace_back(xx, yy);
          }
          if (s.empty()) break;
          std::tie(x, y) = s.back();
          s.pop_back();
        }
        ans += !b;
      }
    return ans;
  }
};
