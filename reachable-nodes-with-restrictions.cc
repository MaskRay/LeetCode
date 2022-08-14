// Reachable Nodes With Restrictions
class Solution {
public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> es(n);
    vector<char> vis(n);
    for (auto &e : edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
    }
    vis[0] = 1;
    for (int r : restricted)
      vis[r] = 1;
    vector q{0};
    for (int i = 0; i != q.size(); i++) {
      int u = q[i];
      for (int v : es[u])
        if (!vis[v]) {
          vis[v] = 1;
          q.push_back(v);
        }
    }
    return q.size();
  }
};
