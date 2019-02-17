// Number of Squareful Arrays
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int numSquarefulPerms(vector<int>& A) {
    int n = A.size(), nn = 1<<n;
    if (n == 1) {
      int q = sqrt(A[0]);
      return q*q == A[0];
    }
    vector<vector<char>> g(n, vector<char>(n));
    REP(i, n)
      REP(j, n) {
        int t = A[i]+A[j], q = sqrt(t);
        g[i][j] = q*q == t;
      }
    vector<vector<int>> p(n, vector<int>(nn)), q(n, vector<int>(nn));
    REP(i, n)
      p[i][1<<i] = 1;
    REP(i, n-1) {
      REP(j, n)
        fill(ALL(q[j]), 0);
      REP(j, n)
        REP(k, nn)
          if (p[j][k])
            REP(jj, n)
              if (!(k & 1<<jj) && g[j][jj])
                q[jj][k | 1<<jj] += p[j][k];
      p.swap(q);
    }
    int ans = 0;
    REP(j, n)
      ans += accumulate(ALL(p[j]), 0);
    unordered_map<int, int> c;
    for (int v : A)
      ans /= ++c[v];
    return ans;
  }
};
