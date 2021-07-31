// Maximum XOR of Two Numbers in an Array
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int r = 0;
    unordered_set<int> s;
    for (int i = 30; i >= 0; i--) {
      int m = r | 1<<i;
      s.clear();
      for (int x: nums)
        s.insert(x & m);
      for (int x: s)
        if (s.count(x^m)) {
          r = m;
          break;
        }
    }
    return r;
  }
};
