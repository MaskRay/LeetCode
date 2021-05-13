// Largest Color Value in a Directed Graph
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size(), top = -1, cnt = 0;
    vector<vector<int>> es(n);
    int ans = 0;
    for (auto &x: edges)
      es[x[0]].push_back(x[1]);

    REP(cc, 26) {
      vector<int> d(n), c(n);
      for (auto &x: edges)
        d[x[1]]++;
      top = -1;
      REP(i, n) {
        if (!d[i]) {
          d[i] = top;
          top = i;
        }
      }
      while (~top) {
        int u = top;
        top = d[top];
        cnt++;
        c[u] += colors[u] == 'a'+cc;
        for (int v: es[u]) {
          c[v] = max(c[v], c[u]);
          if (!--d[v]) {
            d[v] = top;
            top = v;
          }
        }
        ans = max(ans, c[u]);
      }
      if (cnt < n) return -1;
    }
    return ans;
  }
};
