// Maximum Product Subarray
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int maxProduct(int A[], int n) {
    int ans = A[0], mi = A[0], ma = A[0];
    FOR(i, 1, n) {
      int x = mi*A[i], y = ma*A[i];
      mi = min(A[i], min(x, y));
      ma = max(A[i], max(x, y));
      ans = max(ans, ma);
    }
    return ans;
  }
};
