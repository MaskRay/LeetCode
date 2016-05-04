// Reverse String
class Solution {
public:
  string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
  }
};
