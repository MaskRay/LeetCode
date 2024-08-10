// Median of Two Sorted Arrays
class Solution {
public:
  double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
    int m = a.size(), n = b.size(), i = 0, j = 0, k = m+n-1 >> 1;
    while (k > 0) {
      int p = k-1 >> 1;
      if (j+p >= n || i+p < m && a[i+p] < b[j+p])
        i += p+1;
      else
        j += p+1;
      k -= p+1;
    }
    int s = j >= n || i < m && a[i] < b[j] ? a[i++] : b[j++];
    return m+n & 1 ? s : (j >= n || i < m && a[i] < b[j] ? s+a[i] : s+b[j]) * 0.5;
  }
};
