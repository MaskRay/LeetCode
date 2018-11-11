// Reorder Log Files
class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    int n = logs.size();
    vector<array<string, 3>> a;
    for (auto &log : logs) {
      int t = log.find(' ');
      a.push_back({log.substr(t+1), log.substr(0, t), log});
    }
    stable_sort(a.begin(), a.end(), [&](auto &l, auto &r) {
      int dl = l[0][0] <= '9', dr = r[0][0] <= '9';
      if (dl != dr) return dl < dr;
      if (dl) return false;
      return l[0] != r[0] ? l[0] < r[0] : l[1] < r[1];
    });
    vector<string> r;
    for (auto &x: a)
      r.push_back(x[2]);
    return r;
  }
};
