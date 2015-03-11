// Scramble String
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  bool isScramble(string a, string b) {
    int n = a.size();
    vector<vector<vector<bool> > > s(n, vector<vector<bool> >(n, vector<bool>(n)));
    ROF(i, 0, n) {
      REP(j, n)
        if (a[i] == b[j])
          s[i][i][j] = true;
      FOR(j, i+1, n)
        REP(k, n-(j-i)) {
          FOR(l, i, j)
            if (s[i][l][k] && s[l+1][j][k+(l-i+1)] || s[i][l][k+(j-l)] && s[l+1][j][k]) {
              s[i][j][k] = true;
              break;
            }
        }
    }
    return s[0][n-1][0];
  }
};
