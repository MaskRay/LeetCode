// Minimize Xor
class Solution {
public:
  int minimizeXor(int a, int b) {
    int c = 0, t;
    b = __builtin_popcount(b);
    for (; a && b; a ^= t, b--)
      c |= t = 1 << 31-__builtin_clz(a);
    for (; b; b--)
      c |= c+1 & ~c;
    return c;
  }
};
