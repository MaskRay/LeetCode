// Valid Perfect Square
// Hacker's Delight (2nd) 11.1.1
// 46340 = floor(sqrt(INT_MAX))
class Solution {
public:
  bool isPerfectSquare(int num) {
    int x = 46340, y;
    while ((y = (x+num/x)>>1) < x)
      x = y;
    return x*x == num;
  }
};
