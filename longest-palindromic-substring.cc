// Longest Palindromic Substring
// Manacher's algorithm

#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string longestPalindrome(string s) {
    string a(2*s.size()+1, '.');
    vector<int> z(2*s.size()+1);
    REP(i, s.size())
      a[2*i+1] = s[i];
    for (int f, g = 0, i = 0; i < a.size(); i++)
      if (i < g && z[2*f-i] != g-i)
        z[i] = min(z[2*f-i], g-i);
      else {
        f = i;
        g = max(g, i);
        while (g < a.size() && 2*f-g >= 0 && a[g] == a[2*f-g]) g++;
        z[i] = g-f;
      }
    int x = max_element(z.begin(), z.end()) - z.begin();
    return s.substr((x-z[x]+1)/2, z[x]-1);
  }
};
