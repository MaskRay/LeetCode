// Divide Nodes Into the Maximum Number of Groups
// bipartite graph & floodfill
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> color;
  vector<vector<int>> es;
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<int> q0, q1, d;
    int res = 0;
    color.resize(n);
    es.resize(n);
    for (auto &e : edges) {
      es[e[0]-1].push_back(e[1]-1);
      es[e[1]-1].push_back(e[0]-1);
    }
    REP(i, n)
      if (color[i] == 0) {
        q0.assign(1, i);
        color[i] = 1;
        REP(j, q0.size()) {
          int u = q0[j];
          for (int v : es[u])
            if (color[v] == 0) {
              color[v] = color[u]^3;
              q0.push_back(v);
            } else if (color[v] == color[u])
              return -1;
        }
        int mx = 0;
        for (int bgn : q0) {
          q1.assign(1, bgn);
          d.assign(n, -1);
          d[bgn] = 0;
          REP(i, q1.size()) {
            int u = q1[i];
            for (int v : es[u])
              if (d[v] < 0)
                d[v] = d[u]+1, q1.push_back(v);
          }
          mx = max(mx, d[q1.back()]);
        }
        res += mx+1;
      }
    return res;
  }
};
