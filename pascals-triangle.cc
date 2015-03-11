// Pascal's Triangle
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<vector<int> > generate(int n) {
    vector<vector<int>> a;
    REP(i, n) {
      a.emplace_back(i+1);
      a[i][0] = a[i][i] = 1;
      FOR(j, 1, i)
        a[i][j] = a[i-1][j-1] + a[i-1][j];
    }
    return a;
  }
};
