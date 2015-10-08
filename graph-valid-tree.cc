// Graph Valid Tree
class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n-1)
      return false;
    vector<int> djs(n);
    iota(djs.begin(), djs.end(), 0);
    auto f = [&](int x) {
      while (djs[x] != x)
        djs[x] = djs[djs[x]], x = djs[x];
      return x;
    };
    for (auto &e: edges) {
      int x = f(e.first), y = f(e.second);
      if (x == y)
        return false;
      djs[x] = y;
    }
    return true;
  }
};
