// Android Unlock Patterns
class Solution {
  long a[9], r;
  void perm(int k, int m, int n, int used) {
    if (m <= k)
      r++;
    if (k == n)
      return;
    for (int i = k; i < 9; i++) {
      if (k) {
        int x = 10 * min(a[k-1], a[i]) + max(a[k-1], a[i]);
        if (x == 02 && ! (used & 1 << 1) ||
            x == 35 && ! (used & 1 << 4) ||
            x == 68 && ! (used & 1 << 7) ||
            x == 06 && ! (used & 1 << 3) ||
            x == 17 && ! (used & 1 << 4) ||
            x == 28 && ! (used & 1 << 5) ||
            x ==  8 && ! (used & 1 << 4) ||
            x == 26 && ! (used & 1 << 4))
          continue;
      }
      swap(a[i], a[k]);
      perm(k+1, m, n, used | 1 << a[k]);
      swap(a[i], a[k]);
    }
  }
public:
  int numberOfPatterns(int m, int n) {
    r = 0;
    iota(a, a+9, 0);
    perm(0, m, n, 0);
    return r;
  }
};
