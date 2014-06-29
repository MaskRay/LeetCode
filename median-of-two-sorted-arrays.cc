class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      int i = 0, j = 0, k = m+n-1 >> 1;
      while (k > 0) {
        int p = k-1 >> 1;
        if (j+p >= n || i+p < m && A[i+p] < B[j+p])
          i += p+1;
        else
          j += p+1;
        k -= p+1;
      }
      int s = j >= n || i < m && A[i] < B[j] ? A[i++] : B[j++];
      return m+n & 1 ? s : (j >= n || i < m && A[i] < B[j] ? s+A[i] : s+B[j]) * 0.5;
    }
};
