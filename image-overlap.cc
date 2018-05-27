// Image Overlap
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), r = 0;
    FOR(dx, -n+1, n)
      FOR(dy, -n+1, n) {
        int o = 0;
        REP(i, n)
          REP(j, n) {
            int ii = i+dx, jj = j+dy;
            if (B[i][j] && unsigned(ii) < n && unsigned(jj) < n && A[ii][jj])
              o++;
          }
        r = max(r, o);
      }
    return r;
  }
};
