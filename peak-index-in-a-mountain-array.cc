// Peak Index in a Mountain Array
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int l = 0, h = A.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (A[m] < A[m+1]) l = m+1;
      else h = m;
    }
    return l;
  }
};
