// N-Queens II
class Solution {
private:
  int c, n;
public:
  int totalNQueens(int n) {
    this->n = n;
    c = 0;
    f(n, 0, 0, 0);
    return c;
  }
  void f(int i, int l, int m, int r) {
    if (! i)
      c++;
    else
      for (int x = (1<<n)-1&~(l|m|r); x; x &= x-1) {
        int y = x & -x;
        f(i-1, (l|y)<<1, m|y, (r|y)>>1);
      }
  }
};
