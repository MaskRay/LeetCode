// Two City Scheduling
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size()/2;
    nth_element(costs.begin(), costs.begin()+n, costs.end(), [](auto &x, auto &y) {
      return x[0]-x[1] < y[0]-y[1];
    });
    int r = 0;
    for (int i = 0; i < n; i++)
      r += costs[i][0]+costs[i+n][1];
    return r;
  }
};
