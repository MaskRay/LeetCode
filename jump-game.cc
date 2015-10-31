// Jump Game
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  bool canJump(vector<int> &a) {
    int r = 0;
    REP(i, a.size()) {
      if (i > r) break;
      r = max(r, i+a[i]);
    }
    return r >= a.size()-1;
  };
};
