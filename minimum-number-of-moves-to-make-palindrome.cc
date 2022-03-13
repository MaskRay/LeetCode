// Minimum Number of Moves to Make Palindrome
class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int r = 0;
    for (; s.size(); s.pop_back()) {
      int i = s.find(s.back());
      if (i == s.size()-1)
        r += i/2;
      else
        r += i, s.erase(i, 1);
    }
    return r;
  }
};
