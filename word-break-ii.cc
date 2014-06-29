#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
private:
  vector<vector<bool>> f;
  vector<bool> g;
  vector<int> r;
  vector<string> rr;
  void h(int i, int n, const string &s) {
    if (i == n) {
      string ss = s;
      REP(i, r.size()-1)
        ss.insert(r[i]+i, " ");
      rr.push_back(ss);
    } else
      FOR(j, i, n)
        if (f[i][j] && g[j+1]) {
          r.push_back(j+1);
          h(j+1, n, s);
          r.pop_back();
        }
  }
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int n = s.size();
    f.assign(n, vector<bool>(n, false));
    REP(i, n)
      FOR(j, i, n)
        if (dict.count(s.substr(i, j-i+1)))
          f[i][j] = true;
    g.assign(n+1, false);
    g[n] = true;
    ROF(i, 0, n)
      FOR(j, i, n)
        if (f[i][j] && g[j+1]) {
          g[i] = true;
          break;
        }
    r.clear();
    rr.clear();
    h(0, n, s);
    return rr;
  }
};
