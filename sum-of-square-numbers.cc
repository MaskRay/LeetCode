// Sum of Square Numbers
class Solution {
public:
  bool judgeSquareSum(int c) {
    for (long i = 0; i*i <= c; i++) {
      long j = sqrt(c-i*i);
      if (i*i+j*j == c) return true;
    }
    return false;
  }
};
