// Divide Intervals Into Minimum Number of Groups
#define ALL(x) (x).begin(), (x).end()
using pii = pair<int, int>;

class Solution {
public:
  int minGroups(vector<vector<int>>& a) {
    vector<pii> b;
    int s = 0, c = 0;
    for (auto &x : a) {
      b.emplace_back(x[0], 1);
      b.emplace_back(x[1]+1, -1);
    }
    sort(ALL(b));
    for (auto [x, d] : b) {
      c += d;
      s = max(s, c);
    }
    return s;
  }
};
