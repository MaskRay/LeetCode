// Longest Substring with At Most Two Distinct Characters
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    char j = 0, k = 0;
    int r = 0, jc = 0, kc = 0;
    for (int ii = 0, i = 0; i < s.size(); i++) {
      if (s[i] == j)
        jc++;
      else if (s[i] == k)
        kc++;
      else {
        for (; jc && kc; ii++)
          if (s[ii] == j)
            jc--;
          else if (s[ii] == k)
            kc--;
        if (! jc)
          j = s[i], jc = 1;
        else
          k = s[i], kc = 1;
      }
      r = max(r, i-ii+1);
    }
    return r;
  }
};
