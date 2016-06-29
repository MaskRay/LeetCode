// Max Sum of Rectangle No Larger Than K
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = m ? matrix[0].size() : 0, r = INT_MIN;
    if (m > n) {
      vector<vector<int>> a(n, vector<int>(m));
      REP(i, m)
        REP(j, n)
          a[j][i] = matrix[i][j];
      matrix.swap(a);
      swap(m, n);
    }
    REP(i, m) {
      vector<int> a(n, 0);
      FOR(j, i, m) {
        set<int> s;
        s.insert(0);
        int sum = 0;
        REP(l, n) {
          sum += a[l] += matrix[j][l];
          auto it = s.lower_bound(sum-k);
          if (it != s.end())
            r = max(r, sum-*it);
          s.insert(sum);
        }
      }
    }
    return r;
  }
};
