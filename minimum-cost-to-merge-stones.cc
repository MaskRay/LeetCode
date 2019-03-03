// Minimum Cost to Merge Stones
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int mergeStones(vector<int>& a, int K) {
    int n = a.size();
    if ((n-1)%(K-1)) return -1;
    vector<int> sum(n+1);
    REP(i, n)
      sum[i+1] = sum[i] + a[i];
    vector<vector<int>> s(n, vector<int>(n));
    ROF(i, 0, n)
      FOR(j, i+1, n) {
        int t = INT_MAX;
        FOR(g, i+1, j+1)
          if (1+(g-i-1)%(K-1) + 1+(j-g)%(K-1) <= K)
            t = min(t, s[i][g-1]+s[g][j]);
        s[i][j] = t + ((j-i)%(K-1) ? 0 : sum[j+1]-sum[i]);
      }
    return s[0][n-1];
  }
};

/// O(N^2)

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int mergeStones(vector<int>& a, int K) {
    int n = a.size();
    if ((n-1)%--K) return -1;
    vector<int> sum(n+1);
    REP(i, n)
      sum[i+1] = sum[i] + a[i];
    vector<vector<int>> s(n, vector<int>(n)), u(n, vector<int>(n));
    ROF(i, 0, n)
      FOR(j, i, n)
        if (j-i < K)
          u[i][j] = i;
        else {
          int t = INT_MAX, tt, l = u[i][j-K], h = min(u[i+K][j], j-1);
          for (int g = l; g <= h; g += K)
            if ((tt = s[i][g] + s[g+1][j]) < t)
              t = tt, u[i][j] = g;
          s[i][j] = t + ((j-i)%K ? 0 : sum[j+1] - sum[i]);
        }
    return s[0][n-1];
  }
};
