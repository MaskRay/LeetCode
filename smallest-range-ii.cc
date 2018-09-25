// Smallest Range II
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int smallestRangeII(vector<int>& a, int k) {
    sort(ALL(a));
    int mi = a[0], ma = a.back(), r = ma-mi;
    REP(i, a.size()-1)
      r = min(r, max(ma-k,a[i]+k) - min(mi+k,a[i+1]-k));
    return r;
  }
};
