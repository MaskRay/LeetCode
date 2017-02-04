// Smallest Good Base
class Solution {
public:
  string smallestGoodBase(string n2) {
    unsigned long n = stol(n2);
    for (int m = 63-__builtin_clz(n); m > 1; m--) {
      unsigned long x = pow(n, 1.0/m), s = 1, c = 1;
      if (x > 1) {
        for (int i = m; i--; )
          s += c *= x;
        if (s == n)
          return to_string(x);
      }
    }
    return to_string(n-1);
  }
};
