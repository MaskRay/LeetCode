// Bitwise AND of Numbers Range
// __builtin_clz

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    return m == n ? m : m & -1 << 31-__builtin_clz(m^n);
  }
};

//

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    while (m < n)
      n &= n-1;
    return n;
  }
};
