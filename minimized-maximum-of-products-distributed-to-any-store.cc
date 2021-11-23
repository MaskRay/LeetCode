// Minimized Maximum of Products Distributed to Any Store
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int minimizedMaximum(int n, vector<int>& a) {
    long l = 1, h = *max_element(ALL(a));
    while (l < h) {
      long m = l+h >> 1, c = 0;
      for (long x: a)
        c += (x+m-1)/m;
      if (c > n) l = m+1;
      else h = m;
    }
    return l;
  }
};
