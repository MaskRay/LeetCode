// Increment Submatrices by One
class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& qs) {
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &q: qs) {
      int r=q[0], c=q[1], r1=q[2]+1, c1=q[3]+1;
      a[r][c]++;
      if (r1 < n) a[r1][c]--;
      if (c1 < n) a[r][c1]--;
      if (r1<n && c1<n) a[r1][c1]++;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        a[i][j] += (i ? a[i-1][j] : 0) + (j ? a[i][j-1] : 0) - (i&&j ? a[i-1][j-1] : 0);
    return a;
  }
};
