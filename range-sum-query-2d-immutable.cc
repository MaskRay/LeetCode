// Range Sum Query 2D - Immutable
#define REP(i, n) for (int i = 0; i < (n); i++)

class NumMatrix {
  vector<vector<int>> a;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    a = matrix;
    REP(i, a.size())
      REP(j, a[0].size())
      a[i][j] += (i ? a[i-1][j] : 0) + (j ? a[i][j-1] : 0) - (i && j ? a[i-1][j-1] : 0);
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return a[row2][col2] + (row1 && col1 ? a[row1-1][col1-1] : 0)
      - (row1 ? a[row1-1][col2] : 0) - (col1 ? a[row2][col1-1] : 0);
  }
};
