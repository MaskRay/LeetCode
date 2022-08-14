// Minimum Lines to Represent a Line Chart
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

class Solution {
public:
  int minimumLines(vector<vector<int>>& a) {
    sort(ALL(a));
    int n = a.size(),   s = 1;
    if (n == 1) return 0;
    FOR(i, 1, n-1) {
      long x0 = a[i][0]-a[i-1][0], y0 = a[i][1]-a[i-1][1];
      long x1 = a[i][0]-a[i+1][0], y1 = a[i][1]-a[i+1][1];
      s += x0*y1 != x1*y0;
    }
    return s;
  }
};
