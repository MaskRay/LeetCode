// Single Number II

#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
class Solution {
public:
  int singleNumber(vector<int> &a) {
    vector<int> c(32);
    for (int x: a)
      REP(j, 32)
        c[j] += x>>j & 1;
    int r = 0;
    REP(j, 32)
      r += c[j]%3 << j;
    return r;
  }
};

//

class Solution {
public:
  int singleNumber(vector<int> &a) {
    int one = 0, two = 0;
    for (int x: a) {
      one = (one ^ x) & ~ two;
      two = (two ^ x) & ~ one;
    }
    return one;
  }
};
