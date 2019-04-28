// Uncrossed Lines
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> s(n+1, vector<int>(m+1));
    REP(i, n)
      REP(j, m) {
        int ss = 0;
        REP(k, j+1)
          if (A[i]==B[k])
            ss = max(ss, s[i][k]+1);
        REP(k, i+1)
          if (A[k]==B[j])
            ss = max(ss, s[k][j]+1);
        s[i+1][j+1] = max(s[i+1][j],max(s[i][j+1],ss));
      }
    return s[n][m];
  }
};
