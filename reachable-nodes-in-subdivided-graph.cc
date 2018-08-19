// Reachable Nodes In Subdivided Graph
class Solution {
public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N) {
    vector<vector<pair<int,int>>> g(N);
    vector<int> d(N, M+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<char> vis(N);
    int ans = 0;
    for (auto &r : edges) {
      g[r[0]].emplace_back(r[1], r[2] + 1);
      g[r[1]].emplace_back(r[0], r[2] + 1);
    }
    pq.emplace(d[0] = 0, 0);
    while (pq.size()) {
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      ans++;
      for (auto &e : g[u])
        if (d[u] + e.second < d[e.first])
          pq.emplace(d[e.first] = d[u]+e.second, e.first);
    }
    for (auto &r : edges) {
      int u = r[0], v = r[1], w = r[2];
      if (d[u] > d[v])
        swap(u, v);
      int tu = M-d[u];
      if (tu > 0)
        ans += min(tu + max(M-d[v], 0), w);
    }
    return ans;
  }
};
