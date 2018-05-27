// Sum of Distances in Tree
class Solution {
  vector<vector<int>> es;
  vector<int> ss, ans;
  int n;
  int f(int u, int p, int d) {
    int ds = d;
    ss[u] = 1;
    for (int v: es[u])
      if (v != p) {
        ds += f(v, u, d+1);
        ss[u] += ss[v];
      }
    return ds;
  }
  void g(int u, int p, int tot) {
    ans[u] = tot;
    for (int v: es[u])
      if (v != p)
        g(v, u, tot-ss[v]*2+n);
  }
public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    n = N;
    es.resize(N);
    ss.resize(N);
    ans.resize(N);
    for (auto& e:edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
    }
    g(0, -1, f(0, -1, 0));
    return ans;
  }
};
