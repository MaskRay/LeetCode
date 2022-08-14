// Longest Path With Different Adjacent Characters
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  vector<vector<int>> e;
  vector<int> f, g;
  string s;
  void dfs(int u) {
    for (int v: e[u]) {
      dfs(v);
      if (s[u] != s[v])
        g[u] = max(g[u], f[v]+1);
      if (g[u] > f[u])
        swap(f[u], g[u]);
    }
  }
public:
  int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    this->s = std::move(s);
    e.resize(n);
    f.resize(n);
    g.resize(n);
    REP(i, n)
      if (~parent[i])
        e[parent[i]].push_back(i);
    dfs(0);
    int ret = 0;
    REP(i, n)
      ret = max(ret, f[i]+g[i]+1);
    return ret;
  }
};
