// Product of Array Except Self
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &a) {
    int n = (int)a.size(), s = 1;
    vector<int> b(n);
    REP(i, n) {
      b[i] = s;
      s *= a[i];
    }
    s = 1;
    ROF(i, 0, n) {
      b[i] *= s;
      s *= a[i];
    }
    return b;
  }
};
