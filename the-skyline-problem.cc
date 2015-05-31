// The Skyline Problem
class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
    int n = a.size(), xx = -1, x, yy = 0, y = 0;
    priority_queue<pair<int, int>> pq; // order by first, second is insignificant
    vector<pair<int, int>> r;
    for (int i = 0; i < n || pq.size(); ) {
      if (pq.empty() || i < n && a[i][0] < pq.top().second) {
        x = a[i][0];
        pq.emplace(a[i][2], a[i][1]);
        i++;
      } else {
        x = pq.top().second;
        while (pq.size() && pq.top().second <= x)
          pq.pop();
      }
      if (x != xx && y != yy) {
        r.emplace_back(xx, y);
        yy = y;
      }
      xx = x;
      y = pq.empty() ? 0 : pq.top().first;
    }
    if (y != yy)
      r.emplace_back(xx, y);
    return r;
  }
};

///

class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
    vector<pair<int, int>> ev;
    for (auto &e: a) {
      ev.emplace_back(e[0], e[2]);
      ev.emplace_back(e[1], - e[2]);
    }
    sort(ev.begin(), ev.end());
    int x = -1, y = 0, yy = 0;
    multiset<int> h;
    vector<pair<int, int>> r;
    for (auto e: ev) {
      if (e.second > 0)
        h.insert(e.second);
      else
        h.erase(h.find(- e.second));
      if (e.first != x && yy != y) {
        r.emplace_back(x, y);
        yy = y;
      }
      x = e.first;
      y = h.empty() ? 0 : *h.rbegin();
    }
    if (yy != y)
      r.emplace_back(x, y);
    return r;
  }
};
