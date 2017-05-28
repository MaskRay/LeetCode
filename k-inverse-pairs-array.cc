// K Inverse Pairs Array
class Solution {
  static const int MOD = 1000000007;
public:
  int kInversePairs(int n, int k) {
    int a[k+1] = {}, b[k+1];
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
      for (int s = 0, j = 0; j <= k; j++) {
        (s += a[j]) %= MOD;
        if (j >= i) (s += MOD-a[j-i]) %= MOD;
        b[j] = s;
      }
      copy_n(b, k+1, a);
    }
    return a[k];
  }
};
