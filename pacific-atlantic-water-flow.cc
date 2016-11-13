// Pacific Atlantic Water Flow
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return {};
    int m = matrix.size(), n = matrix[0].size();
    queue<pair<int, int>> q;
    vector<vector<char>> a(m, vector<char>(n, 0));
    auto bfs = [&](int b) {
      while (q.size()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if (x && ! (a[x-1][y] & b) && matrix[x][y] <= matrix[x-1][y])
          a[x-1][y] |= b, q.emplace(x-1, y);
        if (x+1 < m && ! (a[x+1][y] & b) && matrix[x][y] <= matrix[x+1][y])
          a[x+1][y] |= b, q.emplace(x+1, y);
        if (y && ! (a[x][y-1] & b) && matrix[x][y] <= matrix[x][y-1])
          a[x][y-1] |= b, q.emplace(x, y-1);
        if (y+1 < n && ! (a[x][y+1] & b) && matrix[x][y] <= matrix[x][y+1])
          a[x][y+1] |= b, q.emplace(x, y+1);
      }
    };
    REP(i, m) {
      q.emplace(i, 0);
      a[i][0] = 1;
    }
    FOR(i, 1, n) {
      q.emplace(0, i);
      a[0][i] = 1;
    }
    bfs(1);
    REP(i, m) {
      q.emplace(i, n-1);
      a[i][n-1] |= 2;
    }
    REP(i, n-1) {
      q.emplace(m-1, i);
      a[m-1][i] |= 2;
    }
    bfs(2);
    vector<pair<int, int>> r;
    REP(i, m)
      REP(j, n)
        if (a[i][j] == 3)
          r.emplace_back(i, j);
    return r;
  }
};
