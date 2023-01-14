// Time to Cross a Bridge
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (n); i++)
using pii = pair<int, int>;

class Solution {
public:
  int findCrossingTime(int n, int k, vector<vector<int>>& a) {
    REP(i, k)
      a[i].push_back(i);
    sort(ALL(a), [](auto &x, auto &y) {
      int l = x[0]+x[2], r = y[0]+y[2];
      if (l != r) return l > r;
      return x[4] > y[4];
    });
    using T = tuple<int, int, int>;
    priority_queue<int, vector<int>, greater<>> l, r;
    priority_queue<T, vector<T>, greater<>> ev;
    bool cross = false;
    int ans = 0, now = 0;
    REP(i, k) l.push(i);
    while (n || l.size() != k) {
      while (ev.size() && get<0>(ev.top()) == now) {
        auto [_, i, state] = ev.top();
        ev.pop();
        if (state == 0) l.push(i);
        else if (state == 1) ev.emplace(now+a[i][1], i, 2), cross = false;
        else if (state == 2) r.push(i);
        else ev.emplace(now+a[i][3], i, 0), cross = false, ans = now;
      }
      if (cross)
        now = get<0>(ev.top());
      else if (r.size()) {
        auto i = r.top();
        r.pop();
        ev.emplace(now+a[i][2], i, 3);
        cross = true;
      } else if (l.size() && n) {
        auto i = l.top();
        l.pop();
        ev.emplace(now+a[i][0], i, 1);
        cross = true;
        n--;
      } else
        now = get<0>(ev.top());
    }
    return ans;
  }
};
