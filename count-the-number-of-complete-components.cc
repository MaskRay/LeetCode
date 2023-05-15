// Count the Number of Complete Components
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> es(n);
    vector<int> vis(n);
    int ret = 0;
    for (auto &e : edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
    }
    REP(i, n)
      if (!vis[i]) {
        vector<int> q{i};
        int c = 0;
        vis[i] = 1;
        REP(j, q.size()) {
          int u = q[j];
          for (int v : es[u])
            if (!vis[v])
              q.push_back(v), vis[v] = 1;
          c += es[u].size();
        }
        ret += c == q.size()*(q.size()-1);
      }
    return ret;
  }
};
