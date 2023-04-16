// Count the Number of Square-Free Subsets
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int squareFreeSubsets(vector<int>& a) {
    const int PS[10] = {2,3,5,7,11,13,17,19,23,29}, MOD = 1000000007;
    vector<int> b(1<<10), c(1<<10);
    b[0] = 1;
    REP(i, a.size()) {
      if (!(a[i]%4 && a[i]%9 && a[i]%25)) continue;
      int x = 0;
      REP(j, 10)
        if (a[i]%PS[j] == 0)
          x |= 1 << j;
      copy(ALL(b), c.begin());
      REP(j, 1<<10)
        if (!(j & x))
          if ((c[j | x] += b[j]) >= MOD)
            c[j | x] -= MOD;
      b.swap(c);
    }
    int s = MOD-1;
    REP(j, 1<<10)
      if ((s += b[j]) >= MOD)
        s -= MOD;
    return s;
  }
};
