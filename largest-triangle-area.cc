// Largest Triangle Area
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &p) {
    long r = 0;
    REP(i, p.size())
    REP(j, i)
    REP(k, j) {
      long t = long(p[j][0] - p[i][0]) * (p[k][1] - p[i][1]) -
               long(p[j][1] - p[i][1]) * (p[k][0] - p[i][0]);
      r = max(r, abs(t));
    }
    return r * 0.5;
  }
};
