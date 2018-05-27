// Magic Squares In Grid
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>>& a) {
    int n = a.size(), s = 0;
    REP(i, n-2)
      REP(j, n-2) {
        char b[10] = {};
        REP(ii, 3)
          REP(jj, 3) {
            if (a[i+ii][j+jj] > 9) goto nxt;
            b[a[i+ii][j+jj]] = 1;
          }
        FOR(i, 1, 10) if (!b[i]) goto nxt;
        REP(k, 3) {
          if (a[i+k][j]+a[i+k][j+1]+a[i+k][j+2] != 15) goto nxt;
          if (a[i][j+k]+a[i+1][j+k]+a[i+2][j+k] != 15) goto nxt;
        }
        if (a[i][j]+a[i+1][j+1]+a[i+2][j+2] != 15) goto nxt;
        s++;
        nxt:;
      }
    return s;
  }
};
