// Minimum Path Sum
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minPathSum(vector<vector<int> > &a) {
    REP(i, a.size())
      REP(j, a[0].size()) {
        if (! i) {
          if (j)
            a[i][j] += a[i][j-1];
        } else if (j)
          a[i][j] += min(a[i-1][j], a[i][j-1]);
        else
          a[i][j] += a[i-1][j];
      }
    return a.back().back();
  }
};
