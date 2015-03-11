// Number of 1 Bits
class Solution {
public:
  int hammingWeight(uint32_t n) {
    const uint32_t X0 = 0x55555555,
          X1 = 0x33333333,
          X2 = 0x0f0f0f0f;
    n = n - (n>>1 & X0);
    n = (n>>2 & X1) + (n & X1);
    n = (n>>4 & X2) + (n & X2);
    return n * 0x01010101 >> 24;
  }
};
