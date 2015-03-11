// First Missing Positive
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    REP(i, n)
      while (0 < A[i] && A[i] <= n && A[A[i]-1] != A[i])
        swap(A[A[i]-1], A[i]);
    REP(i, n)
      if (A[i] != i+1)
        return i+1;
    return n+1;
  }
};
