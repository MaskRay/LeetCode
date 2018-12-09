// Delete Columns to Make Sorted II
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int m = A.size(), n = A[0].size(), r = 0;
    vector<string> b(m);
    REP(c, n) {
      int bad = 0;
      REP(i, m) b[i] += A[i][c];
      REP(i, m-1) if ((bad = b[i] > b[i+1])) break;
      if (bad) REP(i, m) b[i].pop_back();
      else r++;
    }
    return n - r;
  }
};
