// Count Array Pairs Divisible by K
class Solution {
public:
  long long countPairs(vector<int>& nums, int k) {
    vector<int> divisors, c(k+1);
    for (int d = 1; d <= k/d; d++)
      if (k%d == 0) {
        divisors.push_back(d);
        if (d != k/d)
          divisors.push_back(k/d);
      }
    long long ret = 0;
    for (int x: nums) {
      ret += c[k/gcd(k, x)];
      for (int d: divisors)
        if (x%d == 0)
          c[d]++;
    }
    return ret;
  }
};
