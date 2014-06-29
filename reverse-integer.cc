class Solution {
public:
  int reverse(int x) {
    int y = 0;
    do {
      y = y*10+x%10;
      x /= 10;
    } while (x);
    return y;
  }
};
