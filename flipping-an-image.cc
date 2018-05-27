// Flipping an Image
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size();
    REP(i, m) {
      reverse(ALL(A[i]));
      REP(j, n)
        A[i][j] ^= 1;
    }
    return A;
  }
};
