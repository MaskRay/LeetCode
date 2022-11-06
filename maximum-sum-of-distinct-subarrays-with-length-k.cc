// Maximum Sum of Distinct Subarrays With Length K
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  long long maximumSubarraySum(vector<int>& a, int k) {
    long n = a.size(), s = 0, sum = 0;
    unordered_map<int, int> mm;
    vector<int> c(n+1);
    REP(i, k-1) {
      int &t = mm[a[i]];
      c[t]--;
      c[++t]++;
      sum += a[i];
    }
    FOR(i, k-1, n) {
      int &t = mm[a[i]];
      c[t]--;
      c[++t]++;
      sum += a[i];
      if (c[1] == k)
        s = max(s, sum);
      int &t1 = mm[a[i-k+1]];
      c[t1]--;
      c[--t1]++;
      sum -= a[i-k+1];
    }
    return s;
  }
};
