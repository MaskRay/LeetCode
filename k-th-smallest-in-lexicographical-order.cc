// K-th Smallest in Lexicographical Order
class Solution {
public:
  int findKthNumber(int n, int k) {
    long r = 1;
    while (k > 1) {
      long c = 0, x = r, y = r+1;
      for (; x <= n; x *= 10, y *= 10)
        c += min(n+1L, y)-x;
      if (c < k)
        k -= c, r++;
      else
        k--, r *= 10;
    }
    return r;
  }
};
