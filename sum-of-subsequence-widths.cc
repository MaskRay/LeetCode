// Sum of Subsequence Widths
class Solution {
public:
  int sumSubseqWidths(vector<int>& A) {
    const int MOD = 1000000007;
    sort(A.begin(), A.end());
    long x = 0, c = 0, r = 0;
    for (int a: A) {
      r += a*c-x;
      c = (c*2+1)%MOD;
      (x = x*2+a) %= MOD;
    }
    return (r%MOD+MOD)%MOD;
  }
};
