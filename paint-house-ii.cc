// Paint House II
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (! n) return 0;
    int k = costs[0].size();
    FOR(i, 1, n) {
      int w = INT_MAX, ww = INT_MAX;
      REP(j, k) {
        ww = min(ww, costs[i-1][j]);
        if (ww < w)
          swap(w, ww);
      }
      REP(j, k)
        costs[i][j] += w == costs[i-1][j] ? ww : w;
    }
    return *min_element(costs[n-1].begin(), costs[n-1].end());
  }
};
