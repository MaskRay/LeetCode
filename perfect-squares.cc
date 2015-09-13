// Perfect Squares

// Lagrange's four-square theorem
// Legendre's three-square theorem
// expected O((log n)^2): M. O. Rabin, J. O. Shallit, Randomized Algorithms in Number Theory, Communications on Pure and Applied Mathematics 39 (1986), no. S1, pp. S239–S256. doi:10.1002/cpa.3160390713

class Solution {
public:
  int numSquares(int n) {
    while (n % 4 == 0)
      n /= 4;
    if (n % 8 == 7)
      return 4;
    int a = 1, b = sqrt(double(n));
    n -= b * b;
    if (! n)
      return 1;
    b += b - 1;
    while (a-2 <= b) {
      if (n < 0)
        n += b, b -= 2;
      else if (n > 0)
        n -= a, a += 2;
      else
        return 2;
    }
    return 3;
  }
};
