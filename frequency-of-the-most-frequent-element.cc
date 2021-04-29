// Frequency of the Most Frequent Element
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxFrequency(vector<int>& a, int k) {
    long n = a.size(), j = 0, ans = 0, s = k;
    sort(a.begin(), a.end());
    REP(i, n) {
      while ((i-j)*a[i] > s)
        s -= a[j++];
      ans = max(ans, i-j+1);
      s += a[i];
    }
    return ans;
  }
};
