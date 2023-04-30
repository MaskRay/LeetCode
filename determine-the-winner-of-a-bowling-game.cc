// Determine the Winner of a Bowling Game
class Solution {
  int foo(vector<int> &a) {
    int x = 0, y = 0, s = 0;
    for (int z : a) {
      s += z + (x == 10 || y == 10 ? z : 0);
      x = y;
      y = z;
    }
    return s;
  }
public:
  int isWinner(vector<int>& player1, vector<int>& player2) {
    int a = foo(player1), b = foo(player2);
    if (a > b) return 1;
    if (a < b) return 2;
    return 0;
  }
};
