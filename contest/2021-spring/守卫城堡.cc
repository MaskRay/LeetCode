#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

namespace {
const int N = 10000, V = 4*N+3;
struct Edge {int v, c, next; } e[N*12*2];
// src is sink-1
int head[V], allo, sink, h[V+2], nh[V+3];

void insert(int u, int v, int c) {
  e[allo] = Edge{v, c, head[u]}; head[u] = allo++;
  e[allo] = Edge{u, 0, head[v]}; head[v] = allo++;
}

int augment(int u, int d, int sink) {
  if (u == sink) return d;
  int old = d, minh = sink;
  for (int i = head[u]; ~i; i = e[i].next)
    if (e[i].c > 0) {
      int v = e[i].v;
      if (h[v]+1 == h[u]) {
        int dd = augment(v, min(d, e[i].c), sink);
        e[i].c -= dd;
        e[i^1].c += dd;
        if (!(d -= dd) || h[sink-1] > sink) break;
      }
      minh = min(minh, h[v]);
    }
  if (d == old) {
    if (!--nh[h[u]]) h[sink-1] = sink+1;
    nh[h[u] = minh+1]++;
  }
  return old-d;
}
}

class Solution {
public:
  int guardCastle(vector<string>& grid) {
    int n = grid[0].size(), p = 4*n, src = p+1;
    sink = src+1;
    fill_n(head, sink+1, -1);
    allo = 0;

    REP(i, 2) REP(j, n) {
      int v = (2*j+i)*2;
      if (grid[i][j] == '.')
        insert(v, v+1, 1);
      else if (grid[i][j] != '#')
        insert(v, v+1, INT_MAX);

      if (grid[i][j] == 'C')
        insert(src, v, INT_MAX);
      else if (grid[i][j] == 'S')
        insert(v, sink, INT_MAX);
      else if (grid[i][j] == 'P') {
        insert(p, v, INT_MAX);
        insert(v+1, p, INT_MAX);
      }

      REP(d, 4) {
        const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
        unsigned i1 = i+dx[d], j1 = j+dy[d];
        if (i1 < 2 && j1 < n)
          insert(v+1, (2*j1+i1)*2, INT_MAX);
      }
    }

    int flow = 0;
    fill_n(h, sink+1, 0);
    fill_n(nh, sink+2, 0);
    while (h[src] <= sink) {
      flow += augment(src, INT_MAX, sink);
      if (flow >= 2*n) return -1;
    }
    return flow;
  }
};
