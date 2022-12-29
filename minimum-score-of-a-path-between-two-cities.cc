// Minimum Score of a Path Between Two Cities
class Solution {
public:
  int minScore(int n, vector<vector<int>>& rs) {
    vector<vector<pair<int, int>>> es(n);
    for (auto &r : rs) {
      es[r[0]-1].emplace_back(r[1]-1, r[2]);
      es[r[1]-1].emplace_back(r[0]-1, r[2]);
    }
    vector<int> q{0}, vis(n);
    int res = INT_MAX;
    vis[0] = 1;
    while (q.size()) {
      int u = q.back();
      q.pop_back();
      for (auto e : es[u]) {
        res = min(res, e.second);
        if (!vis[e.first])
          vis[e.first] = 1, q.push_back(e.first);
      }
    }
    return res;
  }
};
