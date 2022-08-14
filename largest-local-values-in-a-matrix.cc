// Largest Local Values in a Matrix
#define REP(i, n) for (long i = 0; i < (n); i++)
#define REP1(i, n) for (long i = 1; i <= (n); i++)

class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& a) {
    const int dx[] = {-1,-1,-1,0,1,1,1,0};
    const int dy[] = {-1,0,1,1,1,0,-1,-1};
    int n = a.size();
    vector<vector<int>> b(n-2, vector<int>(n-2));
    REP1(i, n-2)
      REP1(j, n-2) {
        int x = a[i][j];
        REP(k, 8)
          x = max(x, a[i+dx[k]][j+dy[k]]);
        b[i-1][j-1] = x;
      }
    return b;
  }
};
