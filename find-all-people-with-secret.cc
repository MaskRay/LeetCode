// Find All People With Secret
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& a, int first) {
    vector<int> res, uf(n);
    iota(ALL(uf), 0);
    uf[first] = 0;
    auto find = [&](int x) {
      while (uf[x] != x)
        uf[x] = uf[uf[x]], x = uf[x];
      return x;
    };
    sort(ALL(a), [](auto &x, auto &y) { return x[2] < y[2]; });
    for (int j = 0, i = 0; i < a.size(); ) {
      for (; j < a.size() && a[i][2] == a[j][2]; j++)
        uf[find(a[j][0])] = find(a[j][1]);
      for (int u0 = find(0); i < j; i++) {
        if (find(a[i][0]) != u0)
          uf[a[i][0]] = a[i][0];
        if (find(a[i][1]) != u0)
          uf[a[i][1]] = a[i][1];
      }
    }
    int u0 = find(0);
    for (int i = 0; i < n; i++)
      if (find(i) == u0)
        res.push_back(i);
    return res;
  }
};
