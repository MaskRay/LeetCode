// Merge Sorted Array
class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int *C = new int[m+n];
    for (int i = 0, j = 0; i < m || j < n; )
      if (j == n || i < m && A[i] < B[j])
        C[i+j] = A[i], i++;
      else
        C[i+j] = B[j], j++;
    copy(C, C+m+n, A);
    delete[] C;
  }
};
