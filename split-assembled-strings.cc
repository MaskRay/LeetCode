// Split Assembled Strings
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string splitLoopedString(vector<string>& strs) {
    int n = strs.size();
    for (auto &s: strs) {
      string t = s;
      reverse(ALL(t));
      if (t > s) s = t;
    }
    string ans;
    REP(i, n)
      REP(e, 2) {
        REP(j, strs[i].size()) {
          string r = strs[i].substr(j);
          FOR(k, i+1, n) r += strs[k];
          REP(k, i) r += strs[k];
          r += strs[i].substr(0, j);
          ans = max(ans, r);
        }
        reverse(ALL(strs[i]));
      }
    return ans;
  }
};

