// Count the Number of Good Nodes
class Solution {
  int n = 0, res = 0;
  vector<vector<int>> es;
  int dfs(int u, int p) {
    int s = 1, t0 = 0, ok = 1;
    for (int v : es[u])
      if (v != p) {
        int t = dfs(v, u);
        s += t;
        if (t0 && t != t0)
          ok = 0;
        t0 = t;
      }
    res += ok;
    return s;
  }
public:
  int countGoodNodes(vector<vector<int>>& edges) {
    for (auto &e : edges)
      n = max(n, max(e[0], e[1])+1);
    es.resize(n);
    for (auto &e : edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
    }
    dfs(0, -1);
    return res;
  }
};
