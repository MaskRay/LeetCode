// Length of Last Word
class Solution {
public:
  int lengthOfLastWord(const char *s) {
    const char *p = s+strlen(s), *q;
    while (s < p && p[-1] == ' ') p--;
    q = p;
    while (s < p && p[-1] != ' ') p--;
    return q-p;
  }
};
