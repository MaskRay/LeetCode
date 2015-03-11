// Sqrt(x)
// Hacker's Delight (2nd) 11.1.1
// 46340 = floor(sqrt(INT_MAX))
class Solution {
public:
  int sqrt(int x) {
    if (x <= 1) return x;
    int y = 46340, z;
    while ((z = (y+x/y)>>1) < y)
      y = z;
    return y;
  }
};
