// Valid Arrangement of Pairs
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  unordered_map<int, int> p2i, i2p;
  vector<vector<int>> e, ret;
  void hierholzer(int u) {
    while (e[u].size()) {
      int x = e[u].back();
      e[u].pop_back();
      hierholzer(x);
      ret.push_back({i2p[u], i2p[x]});
    }
  }
public:
  vector<vector<int>> validArrangement(vector<vector<int>>& ps) {
    auto fn = [&](int x) -> int {
      auto it = p2i.find(x);
      if (it != p2i.end())
        return it->second;
      int i = i2p.size();
      p2i[x] = i;
      i2p[i] = x;
      return i;
    };
    for (auto &p: ps) {
      p[0] = fn(p[0]);
      p[1] = fn(p[1]);
    }
    int n = p2i.size(), src = 0;
    vector<int> deg(n);
    e.resize(n);
    for (auto &p: ps) {
      deg[p[0]]--;
      deg[p[1]]++;
      e[p[0]].push_back(p[1]);
    }
    REP(i, n)
      if (deg[i] < 0) {
        src = i;
        break;
      }
    hierholzer(src);
    reverse(ALL(ret));
    return ret;
  }
};
