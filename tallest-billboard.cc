// Tallest Billboard
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int tallestBillboard(vector<int>& a) {
    const int M = 5001;
    int n = a.size(), ans = 0;
    if (!n) return 0;
    vector<vector<int>> l(n, vector<int>(M, 0xc0000000));
    vector<int> r(M, 0xc0000000);
    l[0][M/2] = 0;
    REP(i, n-1) {
      l[i+1] = l[i];
      FOR(j, a[i], M) l[i+1][j] = max(l[i+1][j], l[i][j-a[i]] + a[i]);
      REP(j, M-a[i]) l[i+1][j] = max(l[i+1][j], l[i][j+a[i]] + a[i]);
    }
    r[M/2] = 0;
    ROF(i, 0, n) {
      auto r1 = r;
      FOR(j, a[i], M) r1[j] = max(r1[j], r[j-a[i]] + a[i]);
      REP(j, M-a[i]) r1[j] = max(r1[j], r[j+a[i]] + a[i]);
      r.swap(r1);
      REP(j, M) ans = max(ans, l[i][j]+r[j]);
    }
    return ans/2;
  }
};
