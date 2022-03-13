// Minimum Weighted Subgraph With the Required Paths
const int N = 100000;
int heap[N], lkp[N];
long dist[N];

void heap_up(int n, int x) {
  int key = heap[x];
  for (; x && dist[key] < dist[heap[(x-1)/2]]; x = (x-1)/2)
    lkp[heap[x] = heap[(x-1)/2]] = x;
  lkp[heap[x] = key] = x;
}

void heap_down(int n, int x) {
  int key = heap[x];
  for (int y; y = 2*x+1, y < n; x = y) {
    if (y+1 < n && dist[heap[y+1]] < dist[heap[y]]) y++;
    if (!(dist[heap[y]] < dist[key])) break;
    lkp[heap[x] = heap[y]] = x;
  }
  lkp[heap[x] = key] = x;
}

class Solution {
  using pii = pair<int, int>;
public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    auto dijkstra = [&](const vector<pii> *e, int src) -> vector<long> {
      int size = 1;
      fill_n(dist, n, LONG_MAX);
      dist[src] = 0;
      fill_n(lkp, n, -1);
      lkp[heap[0] = src] = 0;
      while (size) {
        int u = exchange(heap[0], heap[--size]);
        lkp[u] = -1;
        if (size) heap_down(size, 0);
        if (dist[u] == LONG_MAX) break;
        for (auto &it: e[u]) {
          long w = dist[u]+it.second;
          int v = it.first;
          if (w < dist[v]) {
            dist[v] = w;
            if (lkp[v] == -1) {
              lkp[heap[size] = v] = size;
              size++;
            }
            heap_up(size, lkp[v]);
          }
        }
      }
      return vector<long>(dist, dist+n);
    };
    auto e = make_unique<vector<pii>[]>(n);
    auto r = make_unique<vector<pii>[]>(n);
    for (auto &x: edges) {
      e[x[0]].emplace_back(x[1], x[2]);
      r[x[1]].emplace_back(x[0], x[2]);
    }
    auto d1 = dijkstra(e.get(), src1);
    auto d2 = dijkstra(e.get(), src2);
    auto d3 = dijkstra(r.get(), dest);
    long ret = LONG_MAX;
    for (int i = 0; i < n; i++)
      if (d1[i] != LONG_MAX && d2[i] != LONG_MAX && d3[i] != LONG_MAX)
        ret = min(ret, d1[i]+d2[i]+d3[i]);
    return ret == LONG_MAX ? -1 : ret;
  }
};
