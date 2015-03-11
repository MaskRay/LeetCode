// Climbing Stairs
class Solution {
public:
  int climbStairs(int n) {
    int a = 1, b = 1, t;
    while (n--)
      t = a+b, a = b, b = t;
    return a;
  }
};
