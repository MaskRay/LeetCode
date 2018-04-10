// Bus Routes
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& a, int S, int T) {
    int N = 1000001;
    vector<vector<vector<int>*>> g(N);
    for (auto& xs: a) {
      sort(ALL(xs));
      xs.erase(unique(ALL(xs)), xs.end());
      for (int x: xs)
        g[x].push_back(&xs);
    }
    vector<int> d(N, -1);
    d[S] = 0;
    queue<int> q;
    q.push(S);
    while (q.size() && d[T] < 0) {
      int u = q.front();
      q.pop();
      for (auto* xs: g[u])
        for (int v: *xs)
          if (d[v] < 0) {
            d[v] = d[u]+1;
            q.push(v);
          }
    }
    return d[T];
  }
};
