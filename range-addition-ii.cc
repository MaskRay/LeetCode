// Range Addition II
class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int r = m, c = n;
    for (auto &op: ops) {
      r = min(r, op[0]);
      c = min(c, op[1]);
    }
    return r*c;
  }
};
