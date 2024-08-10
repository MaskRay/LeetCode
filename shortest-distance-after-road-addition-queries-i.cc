// Shortest Distance After Road Addition Queries I
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> res, d(n);
    vector<vector<int>> es(n);
    for (auto &qu : queries) {
      es[qu[1]].push_back(qu[0]);
      d[0] = 0;
      FOR(i, 1, n) {
        d[i] = d[i-1]+1;
        for (int j : es[i])
          d[i] = min(d[i], d[j]+1);
      }
      res.push_back(d[n-1]);
    }
    return res;
  }
};
