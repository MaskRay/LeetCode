// Find XOR Sum of All Pairs Bitwise AND
class Solution {
public:
  int getXORSum(vector<int>& a, vector<int>& b) {
    return accumulate(a.begin(), a.end(), 0, bit_xor()) &
      accumulate(b.begin(), b.end(), 0, bit_xor());
  }
};
