// Count Primes
// c(n,m) = c(n,m-1) - (c(n/m,m-1)-cnt(m-1))
// cnt(m) = c(m, sqrt(m))

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define REP1(i, n) FOR(i, 1, n+1)

class Solution {
public:
  int countPrimes(int n) {
    if (n < 3)
      return 0;
    int rt = int(sqrt(double(--n)));
    vector<int> v;
    REP1(i, rt)
      v.push_back(n/i);
    ROF(i, 1, v.back())
      v.push_back(i);
    unordered_map<int, int> c;
    for (auto i: v)
      c[i] = i-1;
    FOR(i, 2, rt+1)
      if (c[i-1] < c[i]) {
        int cnt = c[i-1], i2 = i*i;
        for (auto j: v) {
          if (j < i2) break;
          c[j] -= c[j/i]-cnt;
        }
      }
    return c[n];
  }
};
