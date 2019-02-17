// Minimum Number of K Consecutive Bit Flips
class Solution {
public:
  int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), r = 0;
    for (int i = 0; i < n; i++) {
      if (i) A[i] ^= A[i-1]&2;
      if (!A[i] || A[i]==3) {
        if (i > n-K) return -1;
        A[i] ^= 2;
        if (i+K < n) A[i+K] ^= 2;
        r++;
      }
    }
    return r;
  }
};
