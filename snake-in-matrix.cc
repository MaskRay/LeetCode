// Snake in Matrix
class Solution {
public:
  int finalPositionOfSnake(int n, vector<string>& commands) {
    int x = 0;
    for (auto &c : commands)
      switch (c[0]) {
      case 'U': x -= n; break;
      case 'D': x += n; break;
      case 'L': x--; break;
      case 'R': x++;
      }
    return x;
  }
};
