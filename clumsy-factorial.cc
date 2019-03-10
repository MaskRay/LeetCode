// Clumsy Factorial
class Solution {
public:
  int clumsy(int N) {
    if (N <= 2) return N;
    int s = N*(N-1)/(N-2);
    for (N -= 3; N > 0; N -= 4)
      s += N - max(N-1, 0) * max(N-2, 1) / max(N-3, 1);
    return s;
  }
};
