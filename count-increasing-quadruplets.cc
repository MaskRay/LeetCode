// Count Increasing Quadruplets
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  long long countQuadruplets(vector<int>& a) {
    int n = a.size();
    long long ans = 0;
    vector<int> l(n+1);
    REP(j, n) {
      l.assign(n+1, 0);
      REP(i, j) l[a[i]]++;
      REP(i, n) l[i+1] += l[i];
      int gt = 0;
      ROF(i, j+1, n)
        if (a[j] < a[i])
          gt++;
        else
          ans += l[a[i]]*gt;
    }
    return ans;
  }
};

///

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

static short f[4001][4001], g[4001][4001];

class Solution {
public:
  long long countQuadruplets(vector<int>& a) {
    int n = a.size();
    long long res = 0;
    REP(i, n) {
      REP(j, i)
        f[i][j] = (j ? f[i][j-1] : 0) + (a[j] < a[i]);
      ROF(j, i+1, n)
        g[i][j] = (j+1 < n ? g[i][j+1] : 0) + (a[j] > a[i]);
    }
    REP(i, n)
      FOR(j, i+1, n)
        if (a[i] > a[j])
          res += f[j][i] * g[i][j];
    return res;
  }
};
