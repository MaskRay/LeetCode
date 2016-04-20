// Longest Substring with At Most K Distinct Characters
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int c[127] = {}, x = 0, r = 0;
    for (int j = 0, i = 0; i < s.size(); i++) {
      x += ! c[s[i]]++;
      while (x > k)
        x -= ! --c[s[j++]];
      r = max(r, i-j+1);
    }
    return r;
  }
};
