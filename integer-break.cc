// Integer Break
class Solution {
public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n%3 == 0) return pow(3, n/3);
    if (n%3 == 1) return pow(3, (n-4)/3) * 4;
    return pow(3, n/3) * 2;
  }
};
