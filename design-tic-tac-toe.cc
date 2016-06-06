// Design Tic-Tac-Toe
class TicTacToe {
  vector<vector<int8_t>> a;
  int n;
  bool diagonal(int row, int col) {
    if (row != col && row != n-1-col)
      return false;
    int lc = 0, rc = 0;
    for (int i = 0; i < n; i++) {
      lc += a[i][i] == a[row][col];
      rc += a[i][n-1-i] == a[row][col];
    }
    return lc == n || rc == n;
  }
public:
  /** Initialize your data structure here. */
  TicTacToe(int n) : n(n), a(n, vector<int8_t>(n, 0)) {}

  /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
0: No one wins.
1: Player 1 wins.
2: Player 2 wins. */
  int move(int row, int col, int player) {
    a[row][col] = player;
    int rc = 0, cc = 0;
    for (int i = 0; i < n; i++) {
      rc += a[row][i] == player;
      cc += a[i][col] == player;
    }
    return rc == n || cc == n || diagonal(row, col) ? player : 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
