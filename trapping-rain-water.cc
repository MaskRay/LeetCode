// Trapping Rain Water
class Solution {
public:
  int trap(int A[], int n) {
    int hl = 0, hr = 0, i = 0, j = n, s = 0;
    while (i < j) {
      if (hl < hr) {
        s += max(min(hl, hr)-A[i], 0);
        hl = max(hl, A[i++]);
      } else {
        s += max(min(hl, hr)-A[--j], 0);
        hr = max(hr, A[j]);
      }
    }
    return s;
  }
};
