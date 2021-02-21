// Map of Highest Peak
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size(), r, c;
    vector<pair<int, int>> q;
    REP(i, m) REP(j, n)
      if (a[i][j]--)
        q.emplace_back(i, j);
    REP(i, q.size()) {
      tie(r, c) = q[i];
      int t = max(a[r][c]+1, 1);
      if (r && a[r-1][c]<0) a[r-1][c]=t, q.emplace_back(r-1, c);
      if (r+1 < m && a[r+1][c]<0) a[r+1][c]=t, q.emplace_back(r+1, c);
      if (c && a[r][c-1]<0) a[r][c-1]=t, q.emplace_back(r, c-1);
      if (c+1 < n && a[r][c+1]<0) a[r][c+1]=t, q.emplace_back(r, c+1);
    }
    return a;
  }
};
