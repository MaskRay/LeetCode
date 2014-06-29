class Solution {
public:
  int search(int A[], int n, int target) {
    int l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (A[m] == target) return m;
      if (A[l] < A[m]) {
        if (A[l] <= target && target < A[m])
          h = m;
        else
          l = m+1;
      } else {
        if (A[m] < target && target <= A[h-1])
          l = m+1;
        else
          h = m;
      }
    }
    return l < n && A[l] == target ? l : -1;
  }
};
