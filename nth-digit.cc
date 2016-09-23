// Nth Digit
class Solution {
public:
  int findNthDigit(int n) {
    long d = 1, r = 1;
    for (n--; n >= 9*r*d; r *= 10)
      n -= 9*r*d++;
    r += n/d;
    for (d -= n%d+1; d--; )
      r /= 10;
    return r%10;
  }
};
