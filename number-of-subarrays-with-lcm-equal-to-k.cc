// Number of Subarrays With LCM Equal to K
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int subarrayLCM(vector<int>& a, int k) {
    int n = a.size(), s = 0;
    REP(i, n) {
      int x = a[i];
      FOR(j, i, n) {
        x = lcm(x, a[j]);
        if (k%x) break;
        if (k == x) s++;
      }
    }
    return s;
  }
};
