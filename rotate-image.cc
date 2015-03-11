// Rotate Image
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  void rotate(vector<vector<int> > &a) {
    int n = a.size();
    REP(i, n-1)
      REP(j, n-1-i)
        swap(a[i][j], a[n-1-j][n-1-i]);
    REP(i, n/2)
      swap_ranges(a[i].begin(), a[i].end(), a[n-1-i].begin());
  }
};
