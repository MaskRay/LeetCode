// Network Delay Time
using pii = pair<int, int>;

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    struct E { int v, w, next; };
    vector<int> hd(n, -1);
    auto es = make_unique<E[]>(times.size());
    for (int i = 0; i < times.size(); i++) {
      es[i] = {times[i][1]-1, times[i][2], hd[times[i][0]-1]};
      hd[times[i][0]-1] = i;
    }

    priority_queue<pii, vector<pii>, greater<void>> pq;
    int dist[100], num = 0, du, u;
    fill_n(dist, n, INT_MAX);
    dist[--k] = 0;
    pq.emplace(0, k);
    while (pq.size()) {
      tie(du, u) = pq.top();
      pq.pop();
      if (dist[u] < du) continue;
      num++;
      for (int ei = hd[u]; ei >= 0; ei = es[ei].next) {
        int v = es[ei].v, w = du+es[ei].w;
        if (w < dist[v])
          pq.emplace(dist[v] = w, v);
      }
    }
    return num == n ? *max_element(dist, dist+n) : -1;
  }
};
