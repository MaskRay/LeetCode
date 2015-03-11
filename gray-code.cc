// Gray Code
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> r;
    REP(i, 1 << n)
      r.push_back(i^i>>1);
    return r;
  }
};
