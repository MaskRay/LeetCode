// Word Search
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
private:
  bool f(vector<vector<char> > &a, int x, int y, const char *p) {
    if (a[x][y] != *p++) return false;
    a[x][y] = ~a[x][y];
    bool flag = false;
    if (!*p)
      flag = true;
    else
      REP(i, 4) {
        int xx = x+(int[]){-1,0,1,0}[i], yy = y+(int[]){0,1,0,-1}[i];
        if (unsigned(xx) < a.size() && unsigned(yy) < a[0].size() && f(a, xx, yy, p)) {
          flag = true;
          break;
        }
      }
    a[x][y] = ~a[x][y];
    return flag;
  }
public:
  bool exist(vector<vector<char> > &board, string word) {
    if (word.empty()) return true;
    REP(i, board.size())
      REP(j, board[0].size())
        if (f(board, i, j, word.c_str()))
          return true;
    return false;
  }
};

