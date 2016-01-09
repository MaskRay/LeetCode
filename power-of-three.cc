// Power of Three
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && int(pow(3, int(log(INT_MAX) / log(3)))) % n == 0;
  }
};
