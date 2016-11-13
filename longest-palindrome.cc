// Longest Palindrome
class Solution {
public:
  int longestPalindrome(string s) {
    int c[52] = {}, d = 0, r = 0;
    for (char i: s)
      c[i >= 'a' ? i-'a' : i-'A'+26]++;
    for (int i: c) {
      d |= i%2;
      r += i-i%2;
    }
    return r+d;
  }
};
