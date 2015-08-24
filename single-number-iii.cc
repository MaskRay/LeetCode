// Single Number III
class Solution {
public:
  vector<int> singleNumber(vector<int> &a) {
    int k = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
    k &= -k;
    return {
      accumulate(a.begin(), a.end(), 0, [=](int s, int x) { return x & k ? s ^ x : s; }),
      accumulate(a.begin(), a.end(), 0, [=](int s, int x) { return x & k ? s : s ^ x; })
    };
  }
};
