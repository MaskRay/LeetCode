// Check If Word Is Valid After Substitutions
class Solution {
public:
  bool isValid(string S) {
    int n = 0;
    for (char c: S)
      if (c != 'c')
        S[n++] = c;
      else {
        if (n < 2 || S[n-1] != 'b' || S[n-2] != 'a')
          return false;
        n -= 2;
      }
    return !n;
  }
};
