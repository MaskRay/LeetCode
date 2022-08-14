// Number of Arithmetic Triplets
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int arithmeticTriplets(vector<int>& a, int diff) {
    int n = a.size(), s = 0, i = 0, k = 0;
    REP(j, n) {
      int l = 0, r = 0;
      for (; i < j && a[j]-a[i] >= diff; i++)
        l += a[j]-a[i] == diff;
      for (; k < n && a[k]-a[j] <= diff; k++)
        r += a[k]-a[j] == diff;
      s += l*r;
    }
    return s;
  }
};
