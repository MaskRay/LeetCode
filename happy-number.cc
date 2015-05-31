// Happy Number
class Solution {
public:
  bool isHappy(int n) {
    int lam = 1, pw = 1, nn = 1;
    while (n != 1 && n != nn) {
      if (lam == pw) {
        nn = n;
        pw <<= 1;
        lam = 0;
      }
      n = next(n);
      lam++;
    }
    return n == 1;
  }
  int next(int n) {
    int s = 0;
    for (; n; n /= 10)
      s += (n%10)*(n%10);
    return s;
  }
};
