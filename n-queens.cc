// N-Queens
class Solution {
private:
  int n;
  vector<string> s;
  vector<vector<string>> q;
public:
  vector<vector<string>> solveNQueens(int n) {
    q.clear();
    this->n = n;
    s.assign(n, string(n, '.'));
    f(n, 0, 0, 0);
    return q;
  }
  void f(int i, int l, int m, int r) {
    if (! i)
      q.push_back(s);
    else
      for (int x = (1<<n)-1&~(l|m|r); x; x &= x-1) {
        int y = x & -x;
        s[i-1][__builtin_ctz(y)] = 'Q';
        f(i-1, (l|y)<<1, m|y, (r|y)>>1);
        s[i-1][__builtin_ctz(y)] = '.';
      }
  }
};
