// Perfect Number
class Solution {
public:
  bool checkPerfectNumber(int num) {
    int s = 1;
    for (int i = 2; i*i <= num; i++)
      if (num%i == 0) {
        s += i;
        if (i*i < num)
          s += num/i;
      }
    return num > 1 && s == num;
  }
};
