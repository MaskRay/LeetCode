// Set Matrix Zeroes
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  void setZeroes(vector<vector<int> > &a) {
    int m = a.size(), n = a[0].size();
    bool r = count(a[0].begin(), a[0].end(), 0), c = false;
    REP(i, m)
      if (! a[i][0])
        c = true;
    FOR(i, 1, m)
      FOR(j, 1, n)
        if (! a[i][j])
          a[0][j] = a[i][0] = 0;
    FOR(i, 1, m)
      FOR(j, 1, n)
        if (! a[0][j] || ! a[i][0])
          a[i][j] = 0;
    if (r)
      fill(a[0].begin(), a[0].end(), 0);
    if (c)
      REP(i, m)
        a[i][0] = 0;
  }
};
