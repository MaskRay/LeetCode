// 批量处理任务
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)

struct Node {
  int l, r, w;
  bool operator<(const Node &o) const {
    return r < o.r;
  }
};

class Solution {
public:
  int processTasks(vector<vector<int>>& tasks) {
    vector<Node> a;
    for (auto &t: tasks)
      a.push_back(Node{t[0], t[1]+1, t[2]});
    sort(ALL(a));
    a[0].l = a[0].r-a[0].w;
    int m = 1;
    FOR(i, 1, a.size()) {
      int e = a[i].w, j = lower_bound(&a[0], &a[m], a[i], [](const Node &x, const Node &ai) {
        return x.r <= ai.l;
      }) - &a[0];
      if (j < m)
        e -= a[m-1].w-a[j].w + a[j].r-max(a[j].l, a[i].l);
      if (e <= 0) continue;
      int r = a[i].r, d = min(r-a[m-1].r, e), l = r-d;
      e -= d;
      while (e) {
        l = a[--m].l;
        d = min(l - (m?a[m-1].r:0), e);
        l -= d;
        e -= d;
      }
      a[m] = Node{l, r, (m?a[m-1].w:0)+r-l};
      m++;
    }
    return a[m-1].w;
  }
};
