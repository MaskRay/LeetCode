// Maximum XOR of Two Numbers in an Array
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int m = 0, r = 0;
    unordered_set<int> s;
    for (int i = 30; i >= 0; i--) {
      m |= 1<<i;
      s.clear();
      for (int x: nums)
        s.insert(x & m);
      int t = r|1<<i;
      for (int x: s)
        if (s.count(x^t)) {
          r = t;
          break;
        }
    }
    return r;
  }
};
