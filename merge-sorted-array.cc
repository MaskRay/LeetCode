// Merge Sorted Array
class Solution {
public:
  void merge(vector<int> &a, int m, vector<int> &b, int n) {
    vector<int> c(m+n);
    for (int i = 0, j = 0; i < m || j < n; )
      if (j == n || i < m && a[i] < b[j])
        c[i+j] = a[i], i++;
      else
        c[i+j] = b[j], j++;
    a.swap(c);
  }
};
