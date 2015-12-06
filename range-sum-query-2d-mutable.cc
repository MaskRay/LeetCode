// Range Sum Query - Mutable
// 2D Fenwick tree
#define REP(i, n) for (int i = 0; i < (n); i++)

class NumMatrix {
  int m, n;
  vector<vector<int>> a;
  void add(int i, int j, int v) {
    for (; i < m; i |= i+1)
      for (int jj = j; jj < n; jj |= jj+1)
        a[i][jj] += v;
  }
  int sum(int i, int j) {
    int s = 0;
    for (; i; i &= i-1)
      for (int jj = j; jj; jj &= jj-1)
        s += a[i-1][jj-1];
    return s;
  }
public:
  NumMatrix(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = m ? matrix[0].size() : 0;
    a.assign(m, vector<int>(n, 0));
    REP(i, m)
      REP(j, n)
        add(i, j, matrix[i][j]);
  }
  void update(int row, int col, int val) {
    add(row, col, val - sumRegion(row, col, row, col));
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum(row2+1, col2+1) - sum(row1, col2+1)
      - sum(row2+1, col1) + sum(row1, col1);
  }
};
