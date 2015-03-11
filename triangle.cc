// Triangle
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minimumTotal(vector<vector<int> > &a) {
    FOR(i, 1, a.size()) {
      a[i][0] += a[i-1][0];
      a[i][i] += a[i-1][i-1];
      FOR(j, 1, i)
        a[i][j] += min(a[i-1][j-1], a[i-1][j]);
    }
    return *min_element(a.back().begin(), a.back().end());
  }
};
