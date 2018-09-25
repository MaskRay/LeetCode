// Online Election
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class TopVotedCandidate {
  vector<pair<int, int>> a;
public:
  TopVotedCandidate(vector<int> ps, vector<int> ts) {
    int n = ts.size(), l = -1, m = 0;
    vector<int> c(n+1);
    REP(i, n) {
      int p = ps[i];
      if (++c[p] >= m) {
        if (p != l)
          a.emplace_back(ts[i], l = p);
        m = max(m, c[p]);
      }
    }
  }
  int q(int t) {
    return (--upper_bound(ALL(a), std::make_pair(t, INT_MAX)))->second;
  }
};
