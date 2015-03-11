// Longest Substring Without Repeating Characters
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> c(127);
    int r = 0;
    for (int i = 0, j = 0; j < s.size(); i++) {
      for (; j < s.size() && ! c[s[j]]; j++)
        c[s[j]] = true;
      r = max(r, j-i);
      c[s[i]] = false;
    }
    return r;
  }
};
