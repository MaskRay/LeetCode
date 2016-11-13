// Battleships in a Board
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int countBattleships(vector<vector<char>>& a) {
    int r = 0;
    REP(i, a.size())
      REP(j, a[0].size())
        if (a[i][j] == 'X' && (! i || a[i-1][j] != 'X') && (! j || a[i][j-1] != 'X'))
          r++;
    return r;
  }
};
