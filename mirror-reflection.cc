// Mirror Reflection
class Solution {
public:
  int mirrorReflection(int p, int q) {
    long a = p, b = q, t;
    while (b)
      t = a%b, a = b, b = t;
    p = p/a%2;
    q = q/a%2;
    return p && q ? 1 : p ? 0 : 2;
  }
};
