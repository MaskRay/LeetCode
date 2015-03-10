class Solution {
public:
  void rotate(int a[], int n, int k) {
    k = (n-k%n)%n;
    reverse(a, a+k);
    reverse(a+k, a+n);
    reverse(a, a+n);
  }
};
