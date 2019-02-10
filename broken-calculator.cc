// Broken Calculator
class Solution {
public:
  int brokenCalc(int X, int Y) {
    int r = 0;
    for (; X < Y; r++)
      Y = Y & 1 ? Y+1 : Y/2;
    return r+X-Y;
  }
};
