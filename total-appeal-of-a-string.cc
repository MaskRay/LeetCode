// Total Appeal of A String
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  long long appealSum(string s) {
    long ret = 0, n = s.size(), p[128];
    fill_n(p, 128, -1);
    REP(i, n) {
      ret += (i-p[s[i]])*(n-i);
      p[s[i]] = i;
    }
    return ret;
  }
};
