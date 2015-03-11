// Search in Rotated Sorted Array II
class Solution {
public:
  bool search(int A[], int n, int target) {
    int l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (A[m] == target) return true;
      if (A[l] < A[m]) {
        if (A[l] <= target && target < A[m])
          h = m;
        else
          l = m+1;
      } else if (A[l] > A[m]) {
        if (A[m] < target && target <= A[h-1])
          l = m+1;
        else
          h = m;
      } else
        l++;
    }
    return l < n && A[l] == target;
  }
};
