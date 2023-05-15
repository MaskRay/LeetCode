// Neighboring Bitwise XOR
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  bool doesValidArrayExist(vector<int>& d) {
    int n = d.size();
    vector<int> a(n);
    REP(_, 2) {
      int x = _;
      ROF(i, 0, n) {
        a[i] = d[i]^x;
        x = a[i];
      }
      if (a[0] == _)
        return true;
    }
    return false;
  }
};
