// Nested List Weight Sum
class Solution {
  int tot;
  int f(const vector<NestedInteger> &xs) {
    int s = 0;
    for (auto &x: xs)
      if (x.isInteger())
        s += x.getInteger();
      else
        s += f(x.getList());
    tot += s;
    return s;
  }
public:
  int depthSum(vector<NestedInteger>& nestedList) {
    tot = 0;
    f(nestedList);
    return tot;
  }
};
