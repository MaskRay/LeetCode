// Walking Robot Simulation
class Solution {
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int x = 0, y = 0, dx = 0, dy = 1, t, r = 0;
    unordered_map<int, unordered_set<int>> o;
    for (auto &ob : obstacles)
      o[ob[1]].insert(ob[0]);
    for (int c : commands)
      if (c == -2)
        t = dx, dx = -dy, dy = t;
      else if (c == -1)
        t = -dx, dx = dy, dy = t;
      else
        while (c-- && !o[y + dy].count(x + dx)) {
          x += dx, y += dy;
          r = max(r, x * x + y * y);
        }
    return r;
  }
};
