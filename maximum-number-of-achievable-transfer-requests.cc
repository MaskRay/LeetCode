// Maximum Number of Achievable Transfer Requests
// cycle cancelling with Bellman-Ford algorithm, O(n^2*m)
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  struct Arc { int v, c, w, next; };
public:
  int maximumRequests(int n, vector<vector<int>>& reqs) {
    vector<char> vis(n);
    vector<int> d(n), head(n, -1), pred(n);
    vector<Arc> es;
    int cost = 0;
    for (auto &r: reqs) {
      es.push_back({r[1], 1, -1, head[r[0]]});
      head[r[0]] = es.size()-1;
      es.push_back({r[0], 0, 1, head[r[1]]});
      head[r[1]] = es.size()-1;
    }
    for(;;) {
      fill(d.begin(), d.end(), 0);
      fill(pred.begin(), pred.end(), -1);
      REP(k, n-1)
        REP(u, n)
          for (int i = head[u]; ~i; i = es[i].next)
            if (es[i].c > 0 && d[u]+es[i].w < d[es[i].v])
              d[es[i].v] = d[u]+es[i].w, pred[es[i].v] = i;
      int p = -1;
      REP(u, n)
        for (int i = head[u]; ~i; i = es[i].next)
          if (es[i].c > 0 && d[u]+es[i].w < d[es[i].v]) {
            pred[p = es[i].v] = i;
            break;
          }
      if (p < 0) break;
      fill(vis.begin(), vis.end(), 0);
      while (vis[p] = 1, p = es[pred[p]^1].v, !vis[p]);
      int r = p;
      do cost += es[pred[p]].w, es[pred[p]].c--, es[pred[p]^1].c++, p = es[pred[p]^1].v;
      while (p != r);
    }
    return -cost;
  }
};
