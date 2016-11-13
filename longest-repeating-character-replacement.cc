// Longest Repeating Character Replacement
class Solution {
public:
  int characterReplacement(string s, int k) {
    int x = 0, mx = 0, c[127] = {};
    for (int i = 0; i < s.size(); i++) {
      mx = max(mx, ++c[s[i]]);
      if (mx+k <= i-x)
        c[s[x++]]--;
    }
    return s.size()-x;
  }
};
