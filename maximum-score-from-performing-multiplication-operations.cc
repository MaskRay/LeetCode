// Maximum Score from Performing Multiplication Operations
class Solution {
public:
  int maximumScore(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> f(m+1, vector<int>(m+1));
    for (int i = m; i--; )
      for (int j = m-i; --j >= 0; )
        f[i][j] = max(f[i+1][j]+a[i]*b[i+j], f[i][j+1]+a[n-1-j]*b[i+j]);
    return f[0][0];
  }
};
