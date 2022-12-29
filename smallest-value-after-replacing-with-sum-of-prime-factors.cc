// Smallest Value After Replacing With Sum of Prime Factors
class Solution {
  int f(int n) {
    int s = 0;
    for (int i = 2; i*i <= n; i++)
      if (n%i == 0) {
        s += i;
        while ((n /= i) % i == 0)
          s += i;
      }
    if (n > 1)
      s += n;
    return s;
  }
public:
  int smallestValue(int n) {
    int x;
    while ((x = f(n)) != n)
      n = x;
    return x;
  }
};
