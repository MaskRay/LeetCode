// Valid Triangle Number
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int triangleNumber(vector<int>& a) {
    sort(ALL(a));
    int n = a.size(), r = 0;
    REP(i, n)
      if (a[i]) {
        int k = i+1;
        FOR(j, i+1, n) {
          while (k < n && a[i]+a[j] > a[k]) k++;
          r += k-j-1;
        }
      }
    return r;
  }
};
