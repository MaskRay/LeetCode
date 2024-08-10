// Divide Two Integers
class Solution {
public:
  int divide(int p, int q) {
    bool neg = false;
    int r = 0, c = 0;
    if (p > 0)
      p = -p, neg = !neg;
    if (q > 0)
      q = -q, neg = !neg;
    while (q & 1<<30 && p <= q<<1)
      q <<= 1, c++;
    for (; c >= 0; c--, q >>= 1)
      if (p <= q) {
        p -= q;
        r += 1 << c;
      }
    if (r == INT_MIN && !neg)
      return INT_MAX;
    return neg ? -(unsigned)r : r;
  }
};
