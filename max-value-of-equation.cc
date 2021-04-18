// Max Value of Equation
/// monotonicity
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    deque<pair<int, int>> q;
    int ans = INT_MIN;
    for (auto &p: points) {
      int x = p[0], y = p[1];
      while (q.size() && x-q[0].first > k)
        q.pop_front();
      if (q.size())
        ans = max(ans, x+y+q[0].second);
      while (q.size() && q.back().second < y-x)
        q.pop_back();
      q.emplace_back(x, y-x);
    }
    return ans;
  }
};
