#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  bool canJump(int A[], int n) {
    int r = 0;
    REP(i, n) {
      if (i > r) break;
      r = max(r, i+A[i]);
    }
    return r >= n-1;
  };
};
