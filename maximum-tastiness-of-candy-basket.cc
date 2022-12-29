// Maximum Tastiness of Candy Basket
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int maximumTastiness(vector<int>& a, int k) {
    sort(ALL(a));
    long n = a.size(), lo = 0, hi = (a[n-1]-a[0])/(k-1);
    while (lo < hi) {
      long mi = lo+hi+1 >> 1, x = a[0], c = 1;
      REP(i, n)
        if (a[i]-x >= mi)
          x = a[i], c++;
      if (c >= k)
        lo = mi;
      else
        hi = mi-1;
    }
    return lo;
  }
};
