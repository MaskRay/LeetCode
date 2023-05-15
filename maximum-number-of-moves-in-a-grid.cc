// Maximum Number of Moves in a Grid
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maxMoves(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size(), s;
    vector b(m, vector<int>(n));
    FOR(j, 1, n)
      REP(i, m)
        FOR(k, -1, 2)
          if (unsigned(i)+k < m && a[i+k][j-1] < a[i][j] && (j==1 || b[i+k][j-1])) {
            b[i][j] = max(b[i][j], b[i+k][j-1]+1);
            s = max(s, b[i][j]);
          }
    return s;
  }
};
