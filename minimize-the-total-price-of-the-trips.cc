// Minimize the Total Price of the Trips
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
  vector<vector<int>> e;
  vector<int> dep, par, chain, mul;
  int dfs(int u, int p) {
    int size = 1, maxs = 0, s;
    par[u] = p;
    chain[u] = -1;
    for (int v : e[u])
      if (v != p) {
        dep[v] = dep[u]+1;
        if ((s = dfs(v, u)) > maxs)
          maxs = s, chain[u] = v;
        size += s;
      }
    return size;
  }
  void hld(int u, int top) {
    if (chain[u] >= 0) {
      hld(chain[u], top);
      for (int v : e[u])
        if (v != chain[u] && v != par[u])
          hld(v, v);
    }
    chain[u] = top;
  }
  void dfs1(int u) {
    for (int v : e[u])
      if (v != par[u]) {
        dfs1(v);
        mul[u] += mul[v];
      }
  }
  pair<int, int> dp(int u, int p) {
    int f = mul[u], g = mul[u]/2;
    for (int v : e[u])
      if (v != p) {
        auto [x, y] = dp(v, u);
        f += y;
        g += x;
      }
    return {f, min(f, g)};
  }
public:
  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    e.resize(n);
    dep.resize(n);
    par.resize(n);
    chain.resize(n);
    mul.resize(n);
    for (auto &es : edges) {
      e[es[0]].push_back(es[1]);
      e[es[1]].push_back(es[0]);
    }
    dfs(0, -1);
    hld(0, 0);
    for (auto &trip : trips) {
      int u = trip[0], v = trip[1];
      mul[u]++, mul[v]++;
      while (chain[u] != chain[v]) {
        if (dep[chain[u]] > dep[chain[v]])
          swap(u, v);
        v = par[chain[v]];
      }
      if (dep[u] > dep[v])
        swap(u, v);
      mul[u]--;
      if (par[u] >= 0)
        mul[par[u]]--;
    }
    dfs1(0);
    REP(i, n)
      mul[i] *= price[i];
    return dp(0, -1).second;
  }
};
