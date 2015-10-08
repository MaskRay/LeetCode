// Paint Fence
class Solution {
public:
  int numWays(int n, int k) {
    int a = 0, b = k, c = k*k;
    while (n--) {
      a = b;
      b = c;
      c = (a+b)*(k-1);
    }
    return a;
  }
};
