// Factorial Trailing Zeroes
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int trailingZeroes(int n) {
    int r = 0;
    while (n)
      r += n /= 5;
    return r;
  }
};
