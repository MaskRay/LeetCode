#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int jump(int A[], int n) {
    vector<int> dp(n), q(n);
    int *fore = &q[0], *rear = &q[0];
    dp[*rear++ = 0] = 0;
    FOR(i, 1, n) {
      while (fore < rear && *fore+A[*fore] < i) fore++;
      if (fore == rear) return -1;
      dp[i] = dp[*fore]+1;
      if (rear[-1]+A[rear[-1]] < i+A[i]) *rear++ = i;
    }
    return dp[n-1];
  };
};
