// Decode Ways
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty()) return 0;
    vector<int> f(s.size()+1);
    f[0] = 1;
    REP(i, s.size()) {
      f[i+1] = s[i] == '0' ? 0 : f[i];
      if (i && (s[i-1] != '0' && (s[i-1] < '2' || s[i-1] == '2' && s[i] <= '6')))
        f[i+1] += f[i-1];
    }
    return f.back();
  }
};
