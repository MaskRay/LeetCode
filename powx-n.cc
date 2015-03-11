// Pow(x, n)
class Solution {
public:
  double pow(double x, int n) {
    bool neg = n < 0;
    double r = 1;
    if (neg) {
      if (n == INT_MIN) {
        r = x;
        n++;
      }
      n = -n;
    }
    for (; n; n >>= 1, x *= x)
      if (n & 1)
        r *= x;
    if (neg) r = 1./r;
    return r;
  }
};
