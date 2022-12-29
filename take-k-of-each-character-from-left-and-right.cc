// Take K of Each Character From Left and Right
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.size(), ret = n;
    array<int, 3> x = {};
    REP(i, n)
      x[s[i]-'a']++;
    int r = 0;
    if (min({x[0], x[1], x[2]}) < k)
      return -1;
    REP(i, n) {
      for (; r < n && x[s[r]-'a'] > k; r++)
        x[s[r]-'a']--;
      ret = min(ret, int(i+n-r));
      x[s[i]-'a']++;
    }
    return ret;
  }
};
