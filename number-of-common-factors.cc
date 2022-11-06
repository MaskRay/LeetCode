// Number of Common Factors
class Solution {
public:
  int commonFactors(int a, int b) {
    int s = 0;
    a = gcd(a, b);
    for (int i = 1; i*i <= a; i++)
      if (a%i == 0)
        s++, s += i*i != a;
    return s;
  }
};
