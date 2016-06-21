// Count Numbers with Unique Digits
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    int r = 1, p = 9;
    REP(i, min(n, 10)) {
      r += p;
      p *= 9-i;
    }
    return r;
  }
};
