// Split Array Largest Sum
class Solution {
public:
  int splitArray(vector<int>& a, int m) {
    long l = 0, h = 0;
    for (long i: a) {
      l = max(l, i);
      h += i;
    }
    while (l < h) {
      long x = l+h >> 1, s = 0, n = m;
      for (long i: a)
        if ((s += i) > x && (s = i, --n <= 0))
          break;
      if (n <= 0)
        l = x+1;
      else
        h = x;
    }
    return l;
  }
};
