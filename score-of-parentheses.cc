// Score of Parentheses
class Solution {
public:
  int scoreOfParentheses(string S) {
    int r = 0, d = 0, l = 0;
    for (char c : S) {
      if (c == '(')
        d++;
      else if (d--, l == '(')
        r += 1 << d;
      l = c;
    }
    return r;
  }
};
