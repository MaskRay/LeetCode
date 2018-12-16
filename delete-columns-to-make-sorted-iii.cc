// Delete Columns to Make Sorted III
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int m = A.size(), n = A[0].size();
    vector<int> s(n);
    REP(j, n) {
      s[j] = 1;
      REP(jj, j) {
        char ok = 1;
        REP(i, m)
          ok &= A[i][jj] <= A[i][j];
        if (ok)
          s[j] = max(s[j], s[jj] + 1);
      }
    }
    return n - *max_element(ALL(s));
  }
};
