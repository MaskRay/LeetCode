// Count Special Integers
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  int countSpecialNumbers(int n) {
    int m = 0, a[10], u[10] = {};
    n++;
    do a[m++] = n%10;
    while (n /= 10);
    int c = a[m-1], r = c-1;
    u[c] = 1;
    REP(j, m-1)
      r *= 9-j;
    REP(j, m-1) {
      int c = 9;
      REP(k, j)
        c *= 9-k;
      r += c;
    }
    ROF(i, 0, m-1) {
      c = a[i]-accumulate(u, u+a[i], 0);
      REP(j, i)
        c *= 10-m+i-j;
      r += c;
      if (u[a[i]]) break;
      u[a[i]] = 1;
    }
    return r;
  }
};
