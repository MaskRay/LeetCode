// Find Players With Zero or One Losses
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<int> c(100001);
    set<int> id;
    for (auto &m : matches) {
      c[m[1]]++;
      id.insert(m[0]);
    }
    vector<vector<int>> ret(2);
    for (int i : id)
      if (!c[i])
        ret[0].push_back(i);
    REP(i, 100001)
      if (c[i] == 1)
        ret[1].push_back(i);
    return ret;
  }
};
