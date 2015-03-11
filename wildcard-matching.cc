// Wildcard Matching
class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    const char *star = NULL, *ss = s;
    while (*s) {
      if (*p == '?' || *p == *s)
        p++, s++;
      else if (*p == '*')
        star = p++, ss = s;
      else if (star)
        p = star+1, s = ++ss;
      else
        return false;
    }
    while (*p == '*') p++;
    return !*p;
  }
};
