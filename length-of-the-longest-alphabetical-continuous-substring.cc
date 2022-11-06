// Length of the Longest Alphabetical Continuous Substring
class Solution {
public:
  int longestContinuousSubstring(string s) {
    int n = s.size(), r = 0;
    for (int j = 0, i = 0; i < n; ) {
      for (; j<n && s[i]==s[j]-(j-i); j++);
      r = max(r, j-i);
      i = j;
    }
    return min(r, 26);
  }
};
