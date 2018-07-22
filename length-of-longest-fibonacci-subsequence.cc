// Length of Longest Fibonacci Subsequence
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& a) {
    int n = a.size(), r = 0;
    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++)
      for (int k = 0, j = i; j--; ) {
        while (k < j && a[k] < a[i]-a[j])
          k++;
        if (k < j && a[k] == a[i]-a[j]) {
          auto it = dp.find(j*n+k);
          r = max(r, dp[i*n+j] = it != dp.end() ? it->second+1 : 1);
        }
      }
    return r ? r+2 : 0;
  }
};
