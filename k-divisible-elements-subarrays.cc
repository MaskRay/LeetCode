// K Divisible Elements Subarrays
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)
using pii = pair<int, int>;

class Solution {
public:
  int countDistinct(vector<int>& a, int k, int p) {
    int n = a.size(), ret = 0;
    vector<char> div(n);
    vector<pii> b;
    REP(i, n)
      div[i] = a[i]%p == 0;
    REP(i, n) {
      int c = 0;
      FOR(j, i, n) {
        c += div[j];
        if (c > k) break;
        b.emplace_back(i, j-i+1);
      }
    }
    sort(ALL(b), [&](pii x, pii y) {
      if (x.second != y.second)
        return x.second < y.second;
      return lexicographical_compare(&a[x.first], &a[x.first]+x.second, &a[y.first], &a[y.first]+y.second);
    });
    return unique(ALL(b), [&](pii x, pii y) {
      if (x.second != y.second)
        return false;
      return equal(&a[x.first], &a[x.first]+x.second, &a[y.first], &a[y.first]+y.second);
    }) - b.begin();
  }
};
