// Jump Game II
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int jump(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n), q(n);
    int *fore = &q[0], *rear = &q[0];
    dp[*rear++ = 0] = 0;
    FOR(i, 1, n) {
      while (fore < rear && *fore+a[*fore] < i) fore++;
      if (fore == rear) return -1;
      dp[i] = dp[*fore]+1;
      if (rear[-1]+a[rear[-1]] < i+a[i]) *rear++ = i;
    }
    return dp[n-1];
  };
};

///

class Solution {
public:
  int jump(vector<int> &a) {
    int n = a.size(), f = 0, r = 0;
    for (int i = 0; i < n && f < n-1; ) {
      int g = 0;
      for (; i <= f; i++)
        g = max(g, i+a[i]);
      r++;
      f = g;
    }
    return r;
  }
};
