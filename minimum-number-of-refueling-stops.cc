// Minimum Number of Refueling Stops
class Solution {
public:
  int minRefuelStops(int target, int d, vector<vector<int>>& ss) {
    int r = 0, i = 0, n = ss.size();
    priority_queue<int> pq;
    while (d < target) {
      while (i < n && ss[i][0] <= d)
        pq.push(ss[i++][1]);
      if (pq.empty()) return -1;
      d += pq.top();
      pq.pop();
      r++;
    }
    return r;
  }
};
