// Search a 2D Matrix
class Solution {
public:
  bool searchMatrix(vector<vector<int> > &a, int b) {
    int m = a.size(), n = a[0].size(), l = 0, h = m*n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m/n][m%n] < b) l = m+1;
      else h = m;
    }
    return l < m*n && a[l/n][l%n] == b;
  }
};
