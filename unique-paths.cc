// Unique Paths
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int uniquePaths(int m, int n) {
    const int TEN = 10000000;
    int s = 1;
    m--;
    n--;
    n += m;
    vector<int> a(max(n, 1));
    a[0] = 1;
    REP(i, m) {
      int c = 0;
      REP(j, s) {
        a[j] = a[j]*(n-i)+c;
        c = a[j]/TEN;
        a[j] %= TEN;
      }
      if (c) {
        a[s++] = c;
        c = 0;
      }
      ROF(j, 0, s) {
        a[j] = c*TEN+a[j];
        c = a[j]%(i+1);
        a[j] /= i+1;
      }
      while (! a[s-1])
        s--;
    }
    if (s > 1)
      a[0] += a[1]*TEN;
    return a[0];
  }
};
