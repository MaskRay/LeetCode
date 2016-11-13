// Strong Password Checker
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int strongPasswordChecker(string s) {
    int d = 1, A = 1, a = 1;
    vector<int> b;
    for (char c: s)
      if (c <= '9') d = 0;
      else if (c <= 'Z') A = 0;
      else a = 0;
    for (int j = 0, i = 0; i < s.size(); i = j) {
      for (; j < s.size() && s[i] == s[j]; j++);
      if (j-i >= 3)
        b.push_back(j-i);
    }
    if (s.size() < 6)
      return max(d+A+a, 6-int(s.size()));
    int over = max(int(s.size())-20, 0), r = over, replace = 0;
    for (int k = 1; k < 3; k++)
      for (int& i: b)
        if (i%3 == k-1 && over > 0) {
          int t = min(over, k);
          i -= t;
          over -= t;
        }
    for (int& i: b) {
      if (i >= 3 && over > 0) {
        int t = min(i-2, over);
        i -= t;
        over -= t;
      }
      if (i >= 3)
        replace += i/3;
    }
    return r+max(d+A+a, replace);
  }
};
