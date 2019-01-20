// Longest Turbulent Subarray
class Solution {
public:
  int maxTurbulenceSize(vector<int> &A) {
    int n = A.size(), r = 1, dp = 0, s = 0, s1;
    for (int i = 0; i < n-1; i++)
      if (A[i] == A[i+1]) {
        dp = 1;
        s = 0;
      } else {
        s1 = A[i] < A[i+1] ? -1 : 1;
        r = max(r, dp = s == -s1 ? dp+1 : 2);
        s = s1;
      }
    return r;
  }
};
