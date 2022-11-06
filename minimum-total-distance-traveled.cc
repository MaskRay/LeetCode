// Minimum Total Distance Traveled
#define REP(i, n) for (long i = 0; i < (n); i++)

namespace {
const long N = 100, V = N*2+2;
struct Edge { int v, c, w, next; } e[(N+N+N*N) << 1];
long h[V], hsrc;
int head[V], q[V], allo;
bool vis[V];

void insert(int u, int v, int c, int w) {
  e[allo] = {v, c, w, head[u]};
  head[u] = allo++;
  e[allo] = {u, 0, -w, head[v]};
  head[v] = allo++;
}

bool relabel(int n, int src, int sink) {
  int hd = 0, tl = 1;
  q[0] = sink;
  fill_n(vis, n, false);
  fill_n(h, n, LONG_MAX/2);
  h[sink] = 0;
  vis[sink] = true;
  while (hd != tl) {
    int u = q[hd++], v;
    long t;
    if (hd == n) hd = 0;
    vis[u] = false;
    for (int i = head[u]; i >= 0; i = e[i].next)
      if (e[i^1].c && (t = h[u]-e[i].w) < h[v = e[i].v]) {
        h[v] = t;
        if (! vis[v]) {
          vis[v] = true;
          if (t <= h[hd != tl ? q[hd] : src])
            hd == 0 && (hd = n), q[--hd] = v;
          else
            q[tl++] = v, tl == n && (tl = 0);
        }
      }
  }
  REP(u, n)
    for (int i = head[u]; i >= 0; i = e[i].next)
      e[i].w += h[e[i].v]-h[u];
  hsrc += h[src];
  return h[src] < LONG_MAX/2;
}

int augment(int sink, int u, int f) {
  if (u == sink) return f;
  vis[u] = true;
  int old = f;
  for (int i = head[u]; i >= 0; i = e[i].next)
    if (e[i].c && ! vis[e[i].v] && ! e[i].w) {
      int ff = augment(sink, e[i].v, min(f, e[i].c));
      e[i].c -= ff;
      e[i^1].c += ff;
      if (! (f -= ff)) break;
    }
  return old-f;
}
}

class Solution {
public:
  long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& b) {
    const int m = a.size(), n = b.size(), src = m+n, sink = src+1;
    allo = 0;
    fill_n(head, sink+1, -1);
    REP(i, m)
      insert(src, i, 1, 0);
    REP(i, n)
      insert(m+i, sink, b[i][1], 0);
    REP(i, m)
      REP(j, n)
        insert(i, m+j, 1, abs(a[i]-b[j][0]));
    fill_n(h, sink+1, 0);
    hsrc = 0;
    long w, cost = 0;
    while (relabel(sink+1, src, sink))
      while (fill_n(vis, sink+1, false), w = augment(sink, src, INT_MAX))
        cost += w*hsrc;
    return cost;
  };
};

/// minimum-cost flow: successive shortest path algorithm

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

namespace {
const int N = 100, V = N*2+2, E = N+N+N*N;
struct Edge { int v, c, w, next; } e[E << 1];
long h[V];
int q[V], head[V], pre[V], allo;
bool in[V];

void insert(int u, int v, int c, int w) {
  e[allo] = {v, c, w, head[u]};
  head[u] = allo++;
  e[allo] = {u, 0, -w, head[v]};
  head[v] = allo++;
}

bool labelCorrecting(int n, int src, int sink) {
  int *hd = q, *tl = q+1;
  fill_n(in, n, false);
  fill_n(h, n, LONG_MAX);
  h[q[0] = src] = 0;
  while (hd != tl) {
    int u = *hd++;
    if (hd == q+n) hd = q;
    in[u] = false;
    for (int i = head[u]; i >= 0; i = e[i].next)
      if (e[i].c > 0 && h[u]+e[i].w < h[e[i].v]) {
        h[e[i].v] = h[u]+e[i].w;
        pre[e[i].v] = i;
        if (! in[e[i].v]) {
          *tl++ = e[i].v;
          if (tl == q+n) tl = q;
          in[e[i].v] = true;
        }
      }
  }
  return h[sink] < LONG_MAX;
}

long minCost(int n, int src, int sink) {
  long cost = 0, flow = 0;
  while (labelCorrecting(n, src, sink)) {
    int f = INT_MAX;
    for (int v = sink; v != src; v = e[pre[v]^1].v)
      f = min(f, e[pre[v]].c);
    for (int v = sink; v != src; v = e[pre[v]^1].v) {
      e[pre[v]].c -= f;
      e[pre[v]^1].c += f;
    }
    cost += f*h[sink];
    flow += f;
  }
  return cost;
}
}

class Solution {
public:
  long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& b) {
    const int m = a.size(), n = b.size(), src = m+n, sink = src+1;
    allo = 0;
    fill_n(head, sink+1, -1);
    REP(i, m)
      insert(src, i, 1, 0);
    REP(i, n)
      insert(m+i, sink, b[i][1], 0);
    REP(i, m)
      REP(j, n)
        insert(i, m+j, 1, abs(a[i]-b[j][0]));
    return minCost(sink+1, src, sink);
  };
};
