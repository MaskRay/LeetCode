// Sum of k-Mirror Numbers
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

class Solution {
public:
  long long kMirror(int k, int n) {
    long ret = 0, start = 1, stop = 10;
    for (long d = 1; n; d++) {
      FOR(i, start, stop) {
        long x = i, y = d%2 ? i/10 : i;
        for (; y; y /= 10)
          x = x*10+y%10;
        y = 0;
        for (long t = x; t; t /= k)
          y = y*k+t%k;
        if (x == y) {
          ret += x;
          if (--n == 0) break;
        }
      }
      if (d%2 == 0) {
        start = stop;
        stop *= 10;
      }
    }
    return ret;
  }
};

///

class Solution {
  long get(long x, long y) {
    for (; y; y /= 10)
      x = x*10+y%10;
    return x;
  }
  bool is(long x, int k) {
    long y = 0;
    for (long t = x; t; t /= k)
      y = y*k+t%k;
    return x == y;
  }
public:
  long long kMirror(int k, int n) {
    long ret = 0, odd = 1, even = 1, oddPal, evenPal;
    while (n--) {
      while (oddPal = get(odd, odd/10), !is(oddPal, k))
        odd++;
      while (evenPal = get(even, even), !is(evenPal, k) && oddPal > evenPal)
        even++;
      if (oddPal < evenPal)
        ret += oddPal, odd++;
      else
        ret += evenPal, even++;
    }
    return ret;
  }
};
