// Number of Connected Components in an Undirected Graph
class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> uf(n, -1);
    auto find = [&](int x) {
      while (uf[x] >= 0) {
        if (uf[uf[x]] >= 0)
          uf[x] = uf[uf[x]];
        x  = uf[x];
      }
      return x;
    };
    for (auto &e: edges) {
      int u = find(e.first), v = find(e.second);
      if (u != v) {
        n--;
        if (uf[u] > uf[v])
          swap(u, v);
        uf[u] += uf[v];
        uf[v] = u;
      }
    }
    return n;
  }
};

//

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<bool> vis(n, false);
    vector<vector<int>> es(n);
    int comp = 0;
    for (auto &e: edges) {
      es[e.first].push_back(e.second);
      es[e.second].push_back(e.first);
    }
    function<void(int)> dfs = [&](int u) {
      vis[u] = true;
      for (int v: es[u])
        if (! vis[v])
          dfs(v);
    };
    REP(i, n)
      if (! vis[i]) {
        comp++;
        dfs(i);
      }
    return comp;
  }
};
