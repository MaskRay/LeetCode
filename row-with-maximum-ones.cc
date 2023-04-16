// Row With Maximum Ones
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), mc = 0, mo = 0;
    REP(i, m) {
      int c = 0;
      REP(j, n) c += mat[i][j] == 1;
      if (c > mc)
        mc = c, mo = i;
    }
    return {mo, mc};
  }
};
