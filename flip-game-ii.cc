// Flip Game II
class Solution {
public:
  bool canWin(string s) {
    vector<int> sg(s.size()+1, 0), t(s.size()+1, 0);
    int tick = 0;
    for (int i = 2; i <= s.size(); i++) {
      tick++;
      for (int j = i-2; j >= 0; j--)
        t[sg[j]^sg[i-2-j]] = tick;
      sg[i] = find_if(t.begin(), t.end(), bind(not_equal_to<int>(), placeholders::_1, tick)) - t.begin();
    }
    int sum = 0;
    for (auto i = s.begin(); i != s.end(); )
      if (*i == '-')
        ++i;
      else {
        auto j = find(i, s.end(), '-');
        sum ^= sg[j-i];
        i = j;
      }
    return sum;
  }
};
