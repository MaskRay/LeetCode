// Game of Life
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  void gameOfLife(vector<vector<int>> &a) {
    int n = a.size();
    if (! n) return;
    int m = a[0].size();
    REP(i, n)
      REP(j, m)
        if (a[i][j] & 1)
          REP(d, 8) {
            int ii = i+((int[]){-1,-1,-1,0,1,1,1,0})[d], jj = j+((int[]){-1,0,1,1,1,0,-1,-1})[d];
            if (unsigned(ii) < n && unsigned(jj) < m)
              a[ii][jj] += 2;
          }
    REP(i, n)
      REP(j, m)
        a[i][j] = 4 < a[i][j] && a[i][j] < 8;
  }
};
