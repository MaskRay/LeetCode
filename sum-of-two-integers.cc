// Sum of Two Integers
class Solution {
public:
  int getSum(int a, int b) {
    while (b) {
      int t = a;
      a ^= b;
      b = (b&t) << 1;
    }
    return a;
  }
};
