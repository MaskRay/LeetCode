// Frequency of the Most Frequent Element
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxFrequency(vector<int>& a, int k) {
    long n = a.size(), j = 0, ans = 0;
    sort(a.begin(), a.end());
    vector<long> b(n+1);
    REP(i, n)
      b[i+1] = b[i]+a[i];
    REP(i, n) {
      while ((i-j)*a[i]-(b[i]-b[j]) > k)
        j++;
      ans = max(ans, i-j+1);
    }
    return ans;
  }
};
