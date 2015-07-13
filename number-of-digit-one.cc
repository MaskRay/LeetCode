// Number of Digit One
class Solution {
public:
  int countDigitOne(int n) {
    int s = 0, nn = n;
    for (int m = 1; nn; nn /= 10, m *= 10) {
      int a = n/m, b = n%m;
      s += (a+8)/10*m + (a%10 == 1 ? b+1 : 0);
    }
    return s;
  }
};
