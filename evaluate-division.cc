// Evaluate Division
class Solution {
  unordered_map<string, vector<pair<string, double>>> adj;
  unordered_map<string, pair<int, double>> val;
  void dfs(string u, int b, double g) {
    if (val.count(u)) return;
    val[u] = {b, g};
    for (auto& x: adj[u])
      dfs(x.first, b, g*x.second);
  }
public:
  vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    int i = 0;
    for (auto& x: equations) {
      adj[x.first].emplace_back(x.second, values[i]);
      adj[x.second].emplace_back(x.first, 1.0/values[i]);
      i++;
    }
    i = 0;
    for (auto& x: adj)
      dfs(x.first, i++, 1);
    vector<double> r;
    for (auto& x: queries)
      if (! val.count(x.first) || ! val.count(x.second))
        r.push_back(-1);
      else {
        auto &u = val[x.first], &v = val[x.second];
        if (u.first != v.first)
          r.push_back(-1);
        else
          r.push_back(v.second/u.second);
      }
    return r;
  }
};
