// Palindrome Number
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int ten = 1;
    while (x/ten >= 10) ten *= 10;
    while (x) {
      if (x%10 != x/ten) return false;
      x = x%ten/10;
      ten /= 100;
    }
    return true;
  }
};
