// Add Digits
class Solution {
public:
  int addDigits(int num) {
    return num ? num%9 ? num%9 : 9 : 0;
  }
};
