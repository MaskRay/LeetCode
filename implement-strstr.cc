// Implement strStr()
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    int m = strlen(haystack), n = strlen(needle);
    REP(i, m-n+1) {
      int j = 0;
      for (; j < n && haystack[j] == needle[j]; j++);
      if (j == n) return haystack;
      haystack++;
    }
    return NULL;
  }
};
