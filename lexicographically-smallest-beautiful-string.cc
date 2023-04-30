// Lexicographically Smallest Beautiful String
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string smallestBeautifulString(string s, int k) {
    int n = s.size();
    ROF(i, 0, n)
      FOR(c, s[i]+1, min(s[i]+4, 'a'+k)) {
        if (i && s[i-1]==c || i>1 && s[i-2]==c) continue;
        s[i] = c;
        while (++i < n)
          FOR(c, 'a', 'd') {
            if (i && s[i-1]==c || i>1 && s[i-2]==c) continue;
            s[i] = c;
            break;
          }
        return s;
      }
    return "";
  }
};
