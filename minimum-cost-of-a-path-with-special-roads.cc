// Minimum Cost of a Path With Special Roads
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
    int n = roads.size(), ans = abs(start[0]-target[0]) + abs(start[1]-target[1]);
    vector<int> dis(n, INT_MAX-1);
    REP(i, n)
      dis[i] = abs(start[0]-roads[i][0]) + abs(start[1]-roads[i][1]) + roads[i][4];
    for(;;) {
      int u = -1, d = INT_MAX-1;
      REP(i, n)
        if (dis[i] < d)
          d = dis[u = i];
      if (u < 0) break;
      dis[u] = INT_MAX;
      ans = min(ans, d + abs(roads[u][2]-target[0]) + abs(roads[u][3]-target[1]));
      REP(i, n)
        if (dis[i] != INT_MAX)
          dis[i] = min(dis[i], d + abs(roads[u][2]-roads[i][0]) + abs(roads[u][3]-roads[i][1]) + roads[i][4]);
    }
    return ans;
  }
};
