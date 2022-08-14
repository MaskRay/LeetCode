// Maximum Candies Allocated to K Children
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int maximumCandies(vector<int>& a, long long k) {
    long tot = accumulate(ALL(a), 0L), lo = 0, hi = tot/k;
    while (lo < hi) {
      long mi = lo+hi+1 >> 1, c = 0;
      for (int x : a)
        c += x / mi;
      if (c >= k) lo = mi;
      else hi = mi-1;
    }
    return lo;
  }
};
