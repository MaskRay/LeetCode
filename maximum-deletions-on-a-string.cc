// Maximum Deletions on a String
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  int deleteString(string a) {
    int n = a.size();
    vector<int> dp(n+1);
    ROF(i, 0, n) {
      dp[i] = 1;
      int mx = (int(i)+n)/2+1;
      FOR(j, i+1, mx) {
        if (dp[j] < dp[i]) continue;
        int k = 0;
        for (; i+k < j && a[i+k] == a[j+k]; k++);
        if (i+k == j)
          dp[i] = dp[j]+1;
      }
    }
    return dp[0];
  }
};
