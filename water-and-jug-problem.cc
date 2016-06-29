// Water and Jug Problem
class Solution {
public:
  bool canMeasureWater(int x, int y, int z) {
    return ! z || z-x <= y && z % __gcd(x, y) == 0;
  }
};
