// Maximum Trailing Zeros in a Cornered Path
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )
using pii = pair<int, int>;

static pii operator+(pii x, pii y) { return {x.first+y.first, x.second+y.second}; }
static pii operator-(pii x, pii y) { return {x.first-y.first, x.second-y.second}; }

class Solution {
public:
  int maxTrailingZeros(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size(), ret = 0;
    vector<vector<pii>> C(m, vector<pii>(n));
    vector<vector<pii>> U(m, vector<pii>(n));
    vector<vector<pii>> L(m, vector<pii>(n));
    vector<vector<pii>> R(m, vector<pii>(n));
    vector<vector<pii>> D(m, vector<pii>(n));
    REP(i, m)
      REP(j, n) {
        int x = a[i][j], c5 = 0;
        while (x%5 == 0) x /= 5, c5++;
        C[i][j] = {__builtin_ctz(a[i][j]), c5};
        U[i][j] = L[i][j] = C[i][j];
        if (i) U[i][j] = U[i][j]+U[i-1][j];
        if (j) L[i][j] = L[i][j]+L[i][j-1];
      }
    ROF(i, 0, m)
      ROF(j, 0, n) {
        D[i][j] = R[i][j] = C[i][j];
        if (i+1 < m) D[i][j] = D[i][j]+D[i+1][j];
        if (j+1 < n) R[i][j] = R[i][j]+R[i][j+1];
      }
    REP(i, m)
      REP(j, n)
        for (auto x : {U[i][j], D[i][j]})
          for (auto y : {L[i][j], R[i][j]}) {
            auto z = x+y-C[i][j];
            ret = max(ret, min(z.first, z.second));
          }
    return ret;
  }
};
