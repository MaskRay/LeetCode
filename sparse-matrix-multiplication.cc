// Sparse Matrix Multiplication
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), p = B.size(), n = B[0].size();
    unordered_map<int, unordered_map<int, int>> a, b;
    vector<vector<int>> C(m, vector<int>(n, 0));
    REP(i, m)
      REP(j, p)
        if (A[i][j])
          a[i][j] = A[i][j];
    REP(i, p)
      REP(j, n)
        if (B[i][j])
          b[j][i] = B[i][j];
    for (auto &iA: a) {
      int i = iA.first;
      auto &rowA = iA.second;
      for (auto &iB: b) {
        int j = iB.first;
        auto &colB = iB.second;
        for (auto x: rowA)
          if (colB.count(x.first))
            C[i][j] += x.second * colB[x.first];
      }
    }
    return C;
  }
};
