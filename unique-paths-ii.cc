// Unique Paths II
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &a) {
    int m = a.size(), n = a[0].size();
    vector<int> s(n);
    s[0] = 1;
    REP(i, m)
      REP(j, n)
        if (a[i][j] == 1)
          s[j] = 0;
        else if (j)
          s[j] += s[j-1];
    return s[n-1];
  }
};
