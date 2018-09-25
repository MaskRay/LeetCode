// Snakes and Ladders
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) for (remove_cv<remove_reference<decltype(n)>::type>::type i = 1; i <= (n); i++)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size(), k = 0;
    vector<int> b(m*n), d(m*n, -1);
    deque<int> q;
    ROF(i, 0, m)
      if ((m-i-1)%2 == 0)
        REP(j, n)
          b[k++] = a[i][j]-1;
      else
        ROF(j, 0, n)
          b[k++] = a[i][j]-1;
    d[0] = 0;
    for (q.push_back(0); q.size(); ) {
      int x = q.front();
      q.pop_front();
      REP1(i, 6)
        if (x+i < m*n) {
          int y = x+i;
          if (b[y] >= 0) y = b[y];
          if (d[y] < 0) {
            d[y] = d[x]+1;
            q.push_back(y);
          }
        }
    }
    return d[m*n-1];
  }
};
