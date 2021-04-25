// Sum of Digits in Base K
class Solution {
public:
  int sumBase(int n, int k) {
    int s = 0;
    do s += n%k;
    while (n /= k);
    return s;
  }
};
