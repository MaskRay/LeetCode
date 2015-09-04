// H-Index II
class Solution {
public:
  int hIndex(vector<int> &a) {
    int n = (int)a.size(), l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[i] < n-i)
        l = m+1;
      else
        h = m;
    }
    return n-l;
  }
};
