// Maximum Path Quality of a Graph
using pii = pair<int, int>;

class Solution {
  vector<vector<pii>> es;
  vector<int> values, cnt;
  int ans = 0;
public:
  void dfs(int tim, int u, int val) {
    if (!cnt[u]++)
      val += values[u];
    if (u == 0)
      ans = max(ans, val);
    for (auto [v, w]: es[u])
      if (tim >= w)
        dfs(tim-w, v, val);
    if (!--cnt[u])
      val -= values[u];
  }
  int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
    int n = values.size();
    this->values = move(values);
    es.resize(n);
    cnt.resize(n);
    for (auto &e: edges) {
      es[e[0]].emplace_back(e[1], e[2]);
      es[e[1]].emplace_back(e[0], e[2]);
    }
    dfs(maxTime, 0, 0);
    return ans;
  }
};
