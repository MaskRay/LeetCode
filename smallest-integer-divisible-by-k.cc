// Smallest Integer Divisible by K
class Solution {
public:
  int smallestRepunitDivByK(int K) {
    int s = 0;
    for (int i = 0; i < K; i++)
      if (!(s = (s*10+1)%K))
        return i+1;
    return -1;
  }
};
