#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &a) {
    int c[9];
    REP(i, 9) {
      fill_n(c, 9, 0);
      REP(j, 9)
        if (a[i][j] != '.' && ++c[a[i][j]-'1'] > 1)
          return false;
    }
    REP(j, 9) {
      fill_n(c, 9, 0);
      REP(i, 9)
        if (a[i][j] != '.' && ++c[a[i][j]-'1'] > 1)
          return false;
    }
    for (int i = 0; i < 9; i += 3)
      for (int j = 0; j < 9; j += 3) {
        fill_n(c, 9, 0);
        REP(ii, 3)
          REP(jj, 3)
            if (a[i+ii][j+jj] != '.' && ++c[a[i+ii][j+jj]-'1'] > 1)
              return false;
      }
    return true;
  }
};
