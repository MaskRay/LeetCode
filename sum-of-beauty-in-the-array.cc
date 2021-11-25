// Sum of Beauty in the Array
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  int sumOfBeauties(vector<int>& a) {
    int n = a.size(), s = 0, b = a[0];
    vector<int> c(n);
    c[n-1] = a[n-1];
    ROF(i, 0, n-1)
      c[i] = min(c[i+1], a[i]);
    FOR(i, 1, n-1) {
      if (a[i-1] < a[i] && a[i] < a[i+1]) {
        if (b < a[i] && a[i] < c[i+1])
          s++;
        s++;
      }
      b = max(b, a[i]);
    }
    return s;
  }
};
