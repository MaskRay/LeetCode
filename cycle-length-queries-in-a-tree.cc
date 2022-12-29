// Cycle Length Queries in a Tree
class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> r;
    for (auto &q : queries) {
      int u = q[0], v = q[1], s = 1;
      while (u != v) {
        if (u > v) u /= 2;
        else v /= 2;
        s++;
      }
      r.push_back(s);
    }
    return r;
  }
};
