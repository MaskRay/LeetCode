// Integer Replacement
class Solution {
public:
  int integerReplacement(int n) {
    int r = 0;
    unsigned m = n;
    while (m > 3) {
      if (m%2 == 0)
        m >>= 1;
      else if (m&2)
        m++;
      else
        m--;
      r++;
    }
    return r+m-1;
  }
};
