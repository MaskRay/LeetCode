// Minimum Falling Path Sum
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &A) {
    auto a = A;
    int m = a.size(), n = a[0].size();
    FOR(i, 1, m) {
      REP(j, n) {
        int t = a[i-1][j];
        if (j) t = min(t, a[i-1][j-1]);
        if (j+1 < n) t = min(t, a[i-1][j+1]);
        a[i][j] += t;
      };
    }
    return *min_element(ALL(a[m-1]));
  }
};
