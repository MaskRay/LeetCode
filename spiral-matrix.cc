// Spiral Matrix
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (decltype(b) i = (b); --i >= (a); )

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &a) {
    vector<int> r;
    if (a.empty() || a[0].empty()) return r;
    int m = a.size(), n = a[0].size();
    int c = 1;
    REP(i, (min(m,n)+1)/2) {
      FOR(j, i, n-i) r.push_back(a[i][j]);
      FOR(j, i+1, m-i) r.push_back(a[j][n-1-i]);
      if (i < m/2)
        ROF(j, i, n-1-i) r.push_back(a[m-1-i][j]);
      if (i < n/2)
        ROF(j, i+1, m-1-i) r.push_back(a[j][i]);
    }
    return r;
  }
};
