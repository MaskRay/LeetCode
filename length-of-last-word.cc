// Length of Last Word
class Solution {
public:
  int lengthOfLastWord(string a) {
    const char *s = a.c_str();
    int l = 0;
    while (*s) {
      if (*s++ != ' ')
        l++;
      else if (*s && *s != ' ')
        l = 0;
    }
    return l;
  }
};
