// Combinations
// Matters Computational: Ideas, Algorithms, Source Code 6.3
// prefix shifts

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> r;
    vector<bool> b(n);
    auto f = [&]{
      vector<int> a;
      REP(i, n)
        if (b[i])
          a.push_back(i+1);
      r.push_back(a);
    };
    REP(i, k)
      b[i] = 1;
    f();
    if (n > k) {
      b[k] = 1;
      b[0] = 0;
      f();
      int x = 1, y = 0;
      while (x < n-1) {
        b[x++] = 0;
        b[y++] = 1;
        if (b[x] == 0) {
          b[x] = 1;
          b[0] = 0;
          if (y > 1) x = 1;
          y = 0;
        }
        f();
      }
    }
    return r;
  }
};
