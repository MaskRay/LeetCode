// Course Schedule
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool canFinish(int n, vector<vector<int>> &a) {
    vector<int> d(n, 0);
    vector<vector<int>> e(n);
    int top = -1, num = 0;
    for (auto x: a) {
      d[x[0]]++;
      e[x[1]].push_back(x[0]);
    }
    REP(i, n)
      if (! d[i])
        d[i] = top, top = i;
    while (top != -1) {
      int x = top;
      top = d[top];
      num++;
      for (auto y: e[x])
        if (! --d[y])
          d[y] = top, top = y;
    }
    return num == n;
  }
};
