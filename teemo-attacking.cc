// Teemo Attacking
class Solution {
public:
  int findPoisonedDuration(vector<int>& a, int d) {
    int l = INT_MIN, h = INT_MIN, s = 0;
    for (int x: a) {
      if (h < x) {
        s += h-l;
        l = x;
      }
      h = max(h, x+d);
    }
    return s+h-l;
  }
};
