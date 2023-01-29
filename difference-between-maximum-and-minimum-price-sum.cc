// Difference Between Maximum and Minimum Price Sum
class Solution {
  vector<vector<pair<int, int>>> es;
  vector<int> ps;
  vector<long long> memo;
  long long dfs(int u, int p, int id) {
    auto &r = memo[id];
    if (r)
      return r;
    long long s = 0;
    for (auto [v, id1] : es[u])
      if (v != p)
        s = max(s, dfs(v, u, id1));
    return r = s + ps[u];
  }
public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    ps = std::move(price);
    es.resize(n);
    memo.resize(edges.size()*2);
    int id = 0;
    for (auto &e: edges) {
      es[e[0]].emplace_back(e[1], id);
      es[e[1]].emplace_back(e[0], edges.size()+id++);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
      for (auto [v, id]: es[i])
        ans = max(ans, dfs(v, i, id));
    return ans;
  }
};
