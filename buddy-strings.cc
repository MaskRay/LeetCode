// Buddy String
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) return false;
    int n = A.size(), c[26] = {}, d = 0;
    REP(i, n) {
      c[A[i]-'a']++;
      d += A[i] != B[i];
    }
    bool two = *max_element(c, c+26) > 1;
    REP(i, n)
      c[B[i]-'a']--;
    return d == 0 && two || d == 2 && count(c, c+26, 0) == 26;
  }
};
