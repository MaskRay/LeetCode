// Patching Array
class Solution {
public:
  int minPatches(vector<int>& nums, int n) {
    int r = 0;
    long s = 0;
    for (int x: nums) {
      while (s < min(x-1, n)) {
        r++;
        s += s+1;
      }
      s += x;
    }
    while (s < n) {
      r++;
      s += s+1;
    }
    return r;
  }
};
