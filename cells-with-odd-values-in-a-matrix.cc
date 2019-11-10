// Cells with Odd Values in a Matrix
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<int> row(n), col(m);
    for (auto &ind : indices) {
      row[ind[0]] ^= 1;
      col[ind[1]] ^= 1;
    }
    int a[2] = {}, b[2] = {};
    REP(i, n) a[row[i]]++;
    REP(i, m) b[col[i]]++;
    return a[0]*b[1]+a[1]*b[0];
  }
};
