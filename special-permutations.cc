// Special Permutations
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int specialPerm(vector<int>& a) {
    const int MOD = 1000000007;
    int n = a.size(), g[14][14] = {}, c[14][1<<14] = {};
    REP(i, n) REP(j, n)
      if (a[i]%a[j]==0)
        g[i][j] = g[j][i] = 1;
    REP(i, n)
      c[i][1<<i] = 1;
    REP(i, 1<<n)
      REP(j, n)
        if (1<<j & i)
          REP(k, n)
            if (g[j][k] && (1<<k & i)==0)
              (c[k][i|1<<k] += c[j][i]) %= MOD;
    int s = 0;
    REP(j, n)
      (s += c[j][(1<<n)-1]) %= MOD;
    return s;
  }
};
