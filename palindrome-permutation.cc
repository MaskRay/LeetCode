// Palindrome Permutation
class Solution {
public:
  bool canPermutePalindrome(string s) {
    int c[127] = {};
    for (auto x: s)
      c[x]++;
    return count_if(c, c+127, bind(modulus<int>(), placeholders::_1, 2)) == s.size() % 2;
  }
};
