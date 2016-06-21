// Russian Doll Envelopes
class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>>& a) {
    sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
      return x.first != y.first ? x.first < y.first : x.second > y.second;
    });
    vector<int> b;
    for (auto& x: a) {
      auto t = lower_bound(b.begin(), b.end(), x.second);
      if (b.end() == t)
        b.push_back(x.second);
      else
        *t = x.second;
    }
    return b.size();
  }
};
