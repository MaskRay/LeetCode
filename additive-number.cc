// Additive Number
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  bool isAdditiveNumber(string num) {
    int n = num.size();
    ROF(u, 1, n)
      if (num[u] != '0' || u == n-1)
        FOR(v, max(0, 2*u-n), u)
          if (num[v] != '0' || v == u-1) {
            for (int p = n, q = u, r = v; ; ) {
              int i = p, j = q, k = r, zero = 0, b = 0;
              for (; i > q; i--) {
                int t = num[i-1] - (j > r ? num[--j] : '0') - b;
                if (t < 0)
                  t += 10, b = 1;
                else
                  b = 0;
                if (! t)
                  zero++;
                else {
                  for (; zero; zero--)
                    if (! k || num[--k] != '0')
                      goto out;
                  if (! k || num[--k]-'0' != t)
                    goto out;
                }
              }
              if (k == r && (! k || num[--k] != '0'))
                goto out;
              if (! k) {
                if (j == r) return true;
                goto out;
              }
              p = q;
              q = r;
              r = k;
            }
out:;
          }
    return false;
  }
};
