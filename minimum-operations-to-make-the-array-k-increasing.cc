// Minimum Operations to Make the Array K-Increasing
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int kIncreasing(vector<int>& a, int k) {
    int n = a.size(), s = 0;
    vector<int> b;
    REP(si, k) {
      int m = 0;
      b.clear();
      for (int i = si; i < n; i+=k) {
        int j = upper_bound(ALL(b), a[i]) - b.begin();
        if (j == b.size())
          b.push_back(a[i]);
        else
          b[j] = a[i];
        m++;
      }
      s += m-b.size();
    }
    return s;
  }
};
