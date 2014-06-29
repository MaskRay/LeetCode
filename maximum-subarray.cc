// Kadane's algorithm

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maxSubArray(int A[], int n) {
    int r = A[0], s = 0;
    REP(i, n) {
      s = max(s+A[i], A[i]);
      r = max(r, s);
    }
    return r;
  }
};

