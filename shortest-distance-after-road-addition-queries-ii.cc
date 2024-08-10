// Shortest Distance After Road Addition Queries II
class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> res;
    map<int, int> m;
    int s = n-1;
    for (auto &qu : queries) {
      int u = qu[0], v = qu[1];
      auto it = m.lower_bound(u);
      bool del = false;
      while (it != m.end() && it->second <= v) {
        s += it->second-it->first-1;
        it = m.erase(it);
        del = true;
      }
      if (!del && it != m.begin() && (it == m.end() || u < it->first))
        --it;
      if (del || it == m.end() || !(it->first <= u && v <= it->second)) {
        s -= v-u-1;
        m.insert({u, v});
      }
      res.push_back(s);
    }
    return res;
  }
};

/// union-find like
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> res, nxt(n);
    int s = n-1;
    REP(i, n)
      nxt[i] = i+1;
    for (auto &qu : queries) {
      int x = qu[0], y = qu[1];
      if (~nxt[x] && ~nxt[y]) {
        int &r = nxt[x];
        while (x != y) {
          x = exchange(nxt[x], -1);
          s--;
        }
        r = y;
        s++;
      }
      res.push_back(s);
    }
    return res;
  }
};
