// Single Number
class Solution {
public:
  int singleNumber(vector<int> &a) {
    return accumulate(a.begin(), a.end(), 0, bit_xor<int>());
  }
};
