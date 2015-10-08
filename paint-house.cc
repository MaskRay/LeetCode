// Paint House
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (! n) return 0;
    FOR(i, 1, n)
      REP(j, 3)
        costs[i][j] += min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
    return *min_element(costs[n-1].begin(), costs[n-1].end());
  }
};
