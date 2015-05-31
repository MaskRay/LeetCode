// Course Schedule II
class Solution {
public:
  vector<int> findOrder(int n, vector<pair<int, int>>& a) {
    vector<int> d(n, 0), ret;
    for (auto &x: a) {
      swap(x.first, x.second);
      d[x.second]++;
    }
    sort(a.begin(), a.end());
    int top = -1;
    for (int i = 0; i < n; i++)
      if (! d[i])
        d[i] = top, top = i;
    while (top != -1) {
      int x = top;
      top = d[x];
      ret.push_back(x);
      auto i = lower_bound(a.begin(), a.end(), make_pair(x, 0)),
           ii = lower_bound(a.begin(), a.end(), make_pair(x, n));
      for (; i != ii; ++i)
        if (! --d[i->second])
          d[i->second] = top, top = i->second;
    }
    if (ret.size() < n)
      ret.clear();
    return ret;
  }
};
