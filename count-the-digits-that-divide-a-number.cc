// Count the Digits That Divide a Number
class Solution {
public:
  int countDigits(int num) {
    int x = num, s = 0;
    while (s += num%(x%10) == 0, x /= 10);
    return s;
  }
};
