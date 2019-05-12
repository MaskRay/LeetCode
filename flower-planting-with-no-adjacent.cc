// Flower Planting With No Adjacent
class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<int> g[N], c(N);
    for (auto &p: paths) {
      g[p[0]-1].push_back(p[1]-1);
      g[p[1]-1].push_back(p[0]-1);
    }
    for (int i = 0; i < N; i++)
      if (!c[i]) {
        vector<int> q;
        int u = i;
        for(;;) {
          int t[6] = {};
          for (int v: g[u])
            if (c[v])
              t[c[v]] = 1;
            else
              c[v] = 5, q.push_back(v);
          for (int k = 1; ; k++)
            if (!t[k]) {
              c[u] = k;
              break;
            }
          if (q.empty()) break;
          u = q.back();
          q.pop_back();
        }
      }
    return c;
  }
};
