// Reverse Integer
class Solution {
public:
  int reverse(int x) {
    long y = 0;
    do {
      y = y*10+x%10;
      x /= 10;
    } while (x);
    return INT_MIN <= y && y <= INT_MAX ? y : 0;
  }
};
