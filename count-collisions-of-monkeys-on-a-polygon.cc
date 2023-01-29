// Count Collisions of Monkeys on a Polygon
class Solution {
public:
  int monkeyMove(int n) {
    long s = 1, x = 2;
    const int MOD = 1000000007;
    for (; n; n >>= 1, x = x*x%MOD)
      if (n&1)
        s = s*x%MOD;
    return (s+MOD-2)%MOD;
  }
};
