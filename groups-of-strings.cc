// Groups of Strings
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> groupStrings(vector<string>& words) {
    int n = words.size();
    vector<int> a(n), uf(n, -1);
    unordered_map<int, int> m;
    auto find = [&](int x) {
      int r = x, y;
      while (uf[r] >= 0) r = uf[r];
      for (; x != r; x = y) y = uf[x], uf[x] = r;
      return r;
    };
    auto merge = [&](int u, int v) {
      u = find(u);
      v = find(v);
      if (u != v) {
        if (uf[u] > uf[v]) swap(u, v);
        uf[u] += uf[v];
        uf[v] = u;
      }
    };

    REP(i, n) {
      int w = 0;
      for (char c : words[i])
        w |= 1 << c-'a';
      auto r = m.try_emplace(w, i);
      if (!r.second)
        merge(r.first->second, i);
      for (int k = 1<<26; k; k >>= 1)
        if (w & k) {
          r = m.try_emplace(w ^ k, i);
          if (!r.second)
            merge(r.first->second, i);
        }
    }
    return {(int)count_if(ALL(uf), [](int x){return x<0;}), -*min_element(ALL(uf))};
  }
};
