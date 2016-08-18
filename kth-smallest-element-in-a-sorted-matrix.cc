// Kth Smallest Element in a Sorted Matrix
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix[0][0], h = matrix.back().back();
    while (l < h) {
      int x = l+(h-l)/2, c = 0, j = matrix[0].size();
      for (auto& a: matrix) {
        while (j && x < a[j-1])
          j--;
        c += j;
      }
      if (c < k)
        l = x+1;
      else
        h = x;
    }
    return l;
  }
};
