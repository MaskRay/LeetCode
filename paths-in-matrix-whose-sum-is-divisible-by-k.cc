// Paths in Matrix Whose Sum Is Divisible by K
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  static const int P = 1000000007;
public:
  int numberOfPaths(vector<vector<int>>& a, int k) {
    int m = a.size(), n = a[0].size();
    vector<vector<int>> x(n, vector<int>(k));
    vector<vector<int>> y(n, vector<int>(k));
    x[0][0] = 1;
    REP(i, m) {
      REP(j, n) {
        REP(l, k)
          y[j][(l+a[i][j])%k] = x[j][l];
        if (j)
          REP(l, k)
            (y[j][(l+a[i][j])%k] += y[j-1][l]) %= P;
      }
      REP(j, n)
        REP(l, k)
          x[j][l] = exchange(y[j][l], 0);
    }
    return x[n-1][0];
  }
};
