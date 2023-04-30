// First Completely Painted Row or Column
class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int s = arr.size(), m = mat.size(), n = mat[0].size(), ans = s;
    vector<int> c(s);
    REP(i, s)
      c[arr[i]-1] = i;
    REP(i, m) {
      int x = 0;
      REP(j, n)
        x = max(x, mat[i][j] = c[mat[i][j]-1]);
      ans = min(ans, x);
    }
    REP(j, n) {
      int x = 0;
      REP(i, m)
        x = max(x, mat[i][j]);
      ans = min(ans, x);
    }
    return ans;
  }
};
