// Find All Good Indices
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  vector<int> goodIndices(vector<int>& a, int k) {
    int n = a.size(), s = 1;
    vector<int> b(n), r;
    ROF(i, 0, n-1) {
      b[i] = s;
      if (a[i] <= a[i+1]) s++;
      else s = 1;
    }
    s = 1;
    FOR(i, 1, n) {
      if (min(b[i], s) >= k)
        r.push_back(i);
      if (a[i-1] >= a[i]) s++;
      else s = 1;
    }
    return r;
  }
};
