// Count Special Quadruplets
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int countQuadruplets(vector<int>& a) {
    int n = a.size(), ans = 0;
    REP(i, n)
      FOR(j, i+1, n)
        FOR(k, j+1, n) {
          int x = a[i]+a[j]+a[k];
          FOR(l, k+1, n)
            if (x == a[l])
              ans++;
        }
    return ans;
  }
};
