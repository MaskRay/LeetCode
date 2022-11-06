// Number of Good Paths
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& es) {
    auto f = [&](const vector<int> &e) { return max(v[e[0]], v[e[1]]); };
    sort(ALL(es), [&](auto &x, auto &y) { return f(x) < f(y); });
    int n = v.size(), r = n;
    unordered_map<int, vector<int>> pos;
    REP(i, n)
      pos[v[i]].push_back(i);

    vector<int> uf(n), freq(n);
    iota(ALL(uf), 0);
    auto find = [&](int x) {
      int r = x;
      while (uf[r] != r) r = uf[r];
      while (x != r)
        tie(x, uf[x]) = {uf[x], r};
      return x;
    };
    for (int i = 0; i < es.size(); ) {
      int mx = f(es[i]);
      for (; i < es.size() && mx == f(es[i]); i++)
        uf[find(es[i][0])] = find(es[i][1]);
      for (int u : pos[mx])
        r += freq[find(u)]++;
      for (int u : pos[mx])
        freq[uf[u]] = 0;
    }
    return r;
  }
};
