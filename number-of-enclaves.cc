// Number of Enclaves
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int numEnclaves(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size(), one = 0, x, y;
    vector<pair<int, int>> q;
    REP(i, m)
      REP(j, n)
        if (A[i][j]) {
          one++;
          if (!i || !j || i==m-1 || j==n-1) {
            A[i][j] = 0;
            q.emplace_back(i, j);
          }
        }
    REP(i, q.size()) {
      tie(x, y) = q[i];
      if (x && !--A[x-1][y]) q.emplace_back(x-1, y);
      if (x+1<m && !--A[x+1][y]) q.emplace_back(x+1, y);
      if (y && !--A[x][y-1]) q.emplace_back(x, y-1);
      if (y+1<n && !--A[x][y+1]) q.emplace_back(x, y+1);
    }
    return one - q.size();
  }
};
