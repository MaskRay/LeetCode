// Reverse Bits
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    const uint32_t X0 = 0x55555555,
          X1 = 0x33333333,
          X2 = 0x0f0f0f0f,
          X3 = 0x00ff00ff,
          X4 = 0x0000ffff;
    n = n>>1 & X0 | (n&X0) << 1;
    n = n>>2 & X1 | (n&X1) << 2;
    n = n>>4 & X2 | (n&X2) << 4;
    n = n>>8 & X3 | (n&X3) << 8;
    n = n>>16 & X4 | (n&X4) << 16;
    return n;
  }
};
