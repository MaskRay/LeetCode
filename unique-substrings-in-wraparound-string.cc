// Unique Substrings in Wraparound String
class Solution {
public:
  int findSubstringInWraproundString(string p) {
    int r = 0, a[26] = {};
    for (int l = 0, i = 0; i < p.size(); i++) {
      int c = p[i]-'a';
      if (i && p[i-1] != (c+25)%26+'a')
        l = 0;
      if (++l > a[c]) {
        r += l-a[c];
        a[c] = l;
      }
    }
    return r;
  }
};
