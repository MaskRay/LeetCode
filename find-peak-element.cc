// Find Peak Element
class Solution {
public:
  int findPeakElement(const vector<int> &a) {
    int l = 0, h = a.size();
    while (l < h-1) {
      int m = l+h >> 1;
      if (a[m-1] > a[m]) h = m;
      else if (m+1 == h || a[m] < a[m+1]) l = m;
      else l = h = m;
    }
    return l;
  }
};
