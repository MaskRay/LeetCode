// Single-Threaded CPU
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

struct Node {
  int bgn, dur, idx;
  bool operator>(const Node &r) const {
    return tie(dur, idx) > tie(r.dur, r.idx);
  }
};

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    vector<Node> a;
    REP(i, tasks.size())
      a.push_back(Node{tasks[i][0], tasks[i][1], (int)i});
    sort(ALL(a), [](const Node &l, const Node &r) {
      return l.bgn != r.bgn ? l.bgn < r.bgn : l.idx < r.idx;
    });
    priority_queue<Node, vector<Node>, greater<Node>> b;
    int n = a.size(), i = 0;
    long tick = 0;
    vector<int> ans;
    while (i < n || b.size()) {
      if (i < n && a[i].bgn <= tick)
        b.push(a[i++]);
      else if (!b.empty()) {
        ans.push_back(b.top().idx);
        tick += b.top().dur;
        b.pop();
      } else
        tick = a[i].bgn;
    }
    return ans;
  }
};
