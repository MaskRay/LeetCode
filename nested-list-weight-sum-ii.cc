// Nested List Weight Sum II
class Solution {
  int tot;
  pair<int, int> f(const vector<NestedInteger>& xs) {
    int h = 0, s = 0;
    for (auto& x: xs)
      if (x.isInteger())
        s += x.getInteger();
      else {
        auto t = f(x.getList());
        h = max(h, t.first);
        s += t.second;
      }
    tot += s;
    return {h+1, s};
  }
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    tot = 0;
    auto t = f(nestedList);
    return (t.first+1) * t.second - tot;
  }
};
