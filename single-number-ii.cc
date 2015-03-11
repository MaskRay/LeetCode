// Single Number II
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
class Solution {
public:
  int singleNumber(int A[], int n) {
    vector<int> c(32);
    REP(i, n)
      REP(j, 32)
        c[j] += A[i]>>j&1;
    int r = 0;
    REP(j, 32)
      r += c[j]%3 << j;
    return r;
  }
};
