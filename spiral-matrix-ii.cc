// Spiral Matrix II
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (decltype(b) i = (b); --i >= (a); )

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int>> a(n, vector<int>(n));
    int c = 1;
    REP(i, (n+1)/2) {
      FOR(j, i, n-i) a[i][j] = c++;
      FOR(j, i+1, n-i) a[j][n-1-i] = c++;
      ROF(j, i, n-1-i) a[n-1-i][j] = c++;
      ROF(j, i+1, n-1-i) a[j][i] = c++;
    }
    return a;
  }
};
