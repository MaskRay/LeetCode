class Solution {
public:
  int singleNumber(int A[], int n) {
    return accumulate(A, A+n, 0, bit_xor<int>());
  }
};
