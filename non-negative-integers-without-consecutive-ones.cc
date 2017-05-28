// Non-negative Integers without Consecutive Ones
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int findIntegers(int num) {
    const int N = 32-__builtin_clz(num);
    int a[N], b[N] = {}, n = 0, s = 0;
    do a[n++] = num%2;
    while (num /= 2);
    b[0] = 1;
    b[1] = 2;
    FOR(i, 2, n)
      b[i] = b[i-2]+b[i-1];
    ROF(i, 0, n) {
      if (a[i]) {
        s += b[i];
        if (i+1 < n && a[i+1]) break;
      }
      if (! i) s++;
    }
    return s;
  }
};
